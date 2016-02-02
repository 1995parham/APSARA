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

struct sw {
	const struct matching *m;
	int in_port;
	int out_port;
	int **queue;
};

struct sw *switch_new(int in_port, int out_port);

void switch_set_current_matching(struct sw *s, const int match[]);

const struct matching *switch_get_current_matching(const struct sw *s);

void switch_put_in_quque(int in_port, int out_port, int number);

void switch_proccess(void);

void switch_next_matching(struct sw *s);

#endif
