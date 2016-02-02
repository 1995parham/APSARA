/*
 * In The Name Of God
 * ========================================
 * [] File Name : matching.c
 *
 * [] Creation Date : 28-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <stdlib.h>
#include "matching.h"

const struct matching *matching_new(int n, int m, const int match[])
{
	struct matching *new = malloc(sizeof(struct matching));
	new->n = n;
	new->m = m;
	new->match = malloc(sizeof(int) * n);

	int i;
	for (i = 0; i < n; i++)
		new->match[i] = match[i];

	return new;
}

void matching_delete(const struct matching *m)
{
	free(m->match);
	free((void *) m);
}

