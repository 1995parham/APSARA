/*
 * In The Name Of God
 * ========================================
 * [] File Name : switch.h
 *
 * [] Creation Date : 28-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#ifndef SWITCH_H
#define SWITCH_H

#include <stdio.h>

struct sw {
	const struct matching *m;
	int ports;
	int **queue;
	int t;
	int throughput;
};

struct sw *switch_new(int ports);

void switch_set_current_matching(struct sw *s, const int match[]);

void switch_put_in_queue(struct sw *s, int in_port, int out_port, int number);

void switch_process(struct sw *s);

void switch_next_matching(struct sw *s);

void switch_print(struct sw *s, FILE *fp);

#endif
