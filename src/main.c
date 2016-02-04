/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 04-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <stdio.h>
#include <stdlib.h>
#include "switch.h"
#include "matching.h"

#define TEST_NO 4
#define IN_PORTS 4
#define OUT_PORTS 4

int main(int argc, char *argv[])
{
	struct sw *s = switch_new(IN_PORTS, OUT_PORTS);

	int i;
	for (i = 0; i < TEST_NO; i++) {
		switch_print(s, stdout);
		switch_proccess(s);
		int in = rand() % IN_PORTS;
		int out = rand() % OUT_PORTS;
		switch_put_in_queue(s, in, out, 1);
		switch_next_matching(s);
	}
}

