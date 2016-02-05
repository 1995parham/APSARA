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
#include "permutation.h"

static const struct matching **neighbors_matching(const struct matching *m)
{
	const struct matching **res;
	int *match;
	int i, j, counter;

	res = malloc((m->n * (m->n - 1) / 2) * sizeof(struct matching *));
	match = malloc(m->n * sizeof(int));
	for (i = 0; i < m->n; i++)
		match[i] = m->match[i];

	counter = 0;
	for (i = 0; i < m->n; i++) {
		for (j = i + 1; j < m->n; j++) {
			match[i] = m->match[j];
			match[j] = m->match[i];
			res[counter + j - i - 1] = matching_new(m->n, m->m, match);
			match[i] = m->match[i];
			match[j] = m->match[j];
		}
		counter += m->n - i - 1;
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

static const struct matching *hamiltonian_matching(int t, int n, int m)
{
	int i;
	int *v;

	v = malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		v[i] = i;
	permutation(t, v, n);

	const struct matching *res = matching_new(n, m, v);
	free(v);
	return res;
}

void switch_next_matching(struct sw *s)
{
	const struct matching **neighbors;
	const struct matching *hamilton;
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

	hamilton = hamiltonian_matching(s->t + 1, s->out_port, s->in_port);
	int temp = calculate_cost(s->queue, hamilton);
	if (max < temp) {
		index = -2;
		max = temp;
	}

	if (index >= 0)
		switch_set_current_matching(s, neighbors[index]->match);

	if (index == -2)
		switch_set_current_matching(s, hamilton->match);
	
	for (i = 0; i < (s->out_port * (s->out_port - 1) / 2); i++)
			matching_delete(neighbors[i]);
	free(neighbors);
	matching_delete(hamilton);
}
