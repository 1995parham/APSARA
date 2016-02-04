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

void switch_next_matching(struct sw *s)
{
}
