/*
 * In The Name Of God
 * ========================================
 * [] File Name : matching.h
 *
 * [] Creation Date : 28-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#ifndef MATCHING_H
#define MATCHING_H

struct matching {
	int n, m;
	int *match;
};

const struct matching *matching_new(int n, int m, const int match[]);

void matching_delete(const struct matching *m);

#endif
