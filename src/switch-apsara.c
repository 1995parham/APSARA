/*
 * In The Name Of God
 * ========================================
 * [] File Name : switch-apsara.c
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

static const struct matching **neighbors_matching(const struct matching *m)
{
	const struct matching **res;
	int *match;
	int i, j;

	res = malloc((m->n * (m->n - 1) / 2) * sizeof(struct matching *));
	match = malloc(m->n * sizeof(int));
	for (i = 0; i < m->n; i++)
		match[i] = m->match[i];

	for (i = 0; i < m->n; i++) {
		for (j = i; j < m->n; j++) {
			match[i] = m->match[j];
			match[j] = m->match[i];
			res[i * (m->n - 1) + j - i - 1] = matching_new(m->n, m->m, match);
			match[i] = m->match[i];
			match[j] = m->match[j];
		}
	}
	return res;
}

static int calculate_cost(int **queue, const struct matching *m)
{
	int res = 0;
	int i;

	for (i = 0; i < m->n; i++)
		res += queue[m->match[i]][i];

	return res;
}

void switch_next_matching(struct sw *s)
{
	const struct matching **neighbors;
	int index;
	int max;
	int i;

	neighbors = neighbors_matching(s->m);
	index = -1;
	max = calculate_cost(s->queue, s->m);
	for (i = 0; i < (s->out_port * (s->out_port - 1) / 2); i++) {
		int temp = calculate_cost(s->queue, neighbors[i]);
		if (max < temp) {
			index = i;
			max = temp;
		}
	}

	if (index != -1)
		s->m = neighbors[index];
	
	for (i = 0; i < (s->out_port * (s->out_port - 1) / 2); i++)
		if (index != i)
			matching_delete(neighbors[i]);
}
