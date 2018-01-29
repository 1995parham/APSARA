/*
 * In The Name Of God
 * ========================================
 * [] File Name : switch.c
 *
 * [] Creation Date : 03-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <stdlib.h>
#include <stdio.h>
#include "switch.h"
#include "matching.h"

struct sw *switch_new(int ports)
{
	struct sw *new = malloc(sizeof(struct sw));
	new->ports = ports;
	
	int i, j;
	new->queue = malloc(ports * sizeof(int *));
	for (i = 0; i < ports; i++) {
		new->queue[i] = malloc(ports * sizeof(int));
		for (j = 0; j < ports; j++)
			new->queue[i][j] = 0;
	}

	int *match = malloc(ports * sizeof(int));
	for (i = 0; i < ports && i < ports; i++)
		match[i] = i;
	new->m = matching_new(ports, match);
	free(match);

	new->t = 0;

	new->throughput = 0;

	return new;	
}

void switch_set_current_matching(struct sw *s, const int match[])
{
	matching_delete(s->m);
	s->m = matching_new(s->ports, match);
}

void switch_put_in_queue(struct sw *s, int in_port, int out_port, int number)
{
	s->queue[in_port][out_port] += number;
}

void switch_process(struct sw *s)
{
	int i;
	for (i = 0; i < s->ports; i++) {
		if (s->queue[i][s->m->match[i]] > 0) {
			s->throughput += 1;
			s->queue[i][s->m->match[i]] -= 1;
		}
	}
	s->t++;
}

void switch_print(struct sw *s, FILE *fp)
{
	int i, j;

	fprintf(fp, "======== SWITCH [%d] ========\n", s->t);
	
	fprintf(fp, "\n\n");

	fprintf(fp, "-------- QUEUES --------\n");

	fprintf(fp, "in/out ");
	for (i = 0; i < s->ports; i++)
		fprintf(fp, "%6d ", i + 1);
	fprintf(fp, "\n");
	for (i = 0; i < s->ports; i++) {
		fprintf(fp, "%6d ", i + 1);
		for (j = 0; j < s->ports; j++) {
			fprintf(fp, "%6d ", s->queue[i][j]);	
		}
		fprintf(fp, "\n");
	}
	
	fprintf(fp, "\n\n");
	
	fprintf(fp, "-------- MATCHING --------\n");

	matching_print(s->m, fp);
}
