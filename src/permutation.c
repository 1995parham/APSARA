/*
 * In The Name Of God
 * ========================================
 * [] File Name : permutation.c
 *
 * [] Creation Date : 04-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include "permutation.h"

static void swap(int *v, int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

static void next(int *v, int size)
{
	int k,j,r,s;
	k = size - 2;
	
	while (v[k] > v[k + 1])
		k--;
	
	if (k == 0) {
		return;
	} else {
		j = size - 1;
		while (v[k] > v[j])
			j--;
		swap(v, j, k);
		r = size - 1;
		s = k + 1;
		
		while (r>s) {
			swap(v, r, s);
			r--;
			s++;
		}
	}
}

void permutation(int k, int *v, int size)
{
	int i;

	for(i = 0; i < k; i++)
		next(v, size);

}
