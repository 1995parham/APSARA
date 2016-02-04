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
#include "switch.h"
#include "matching.h"

struct sw *switch_new(int in_port, int out_port)
{
	struct sw *new = malloc(sizeof(struct sw));
	new->in_port = in_port;
	new->out_port = out_port;
	
	int i, j;
	new->queue = malloc(in_port * sizeof(int *));
	for (i = 0; i < in_port; i++) {
		new->queue[i] = malloc(out_port * sizeof(int));
		for (j = 0; j < out_port; j++)
			new->queue[i][j] = 0;
	}

	int *match = malloc(out_port * sizeof(int));
	for (i = 0; i < out_port && i < in_port; i++)
		match[i] = i;
	new->m = matching_new(out_port, in_port, match);
	free(match);

	return new;	
}

void switch_set_current_matching(struct sw *s, const int match[])
{
	matching_delete(s->m);
	s->m = matching_new(s->out_port, s->in_port, match);
}

void switch_put_in_quque(struct sw *s, int in_port, int out_port, int number)
{
	s->queue[in_port][out_port] += number;
}

void switch_proccess(struct sw *s)
{
	int i;
	for (i = 0; i < s->out_port; i++)
		s->queue[i][s->m->match[i]] = 0;
}