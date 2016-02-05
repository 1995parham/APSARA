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

int main(int argc, char *argv[])
{
	int test_no, ports, printing;

	printf("Simulation Times: ");
	scanf("%d", &test_no);
	
	printf("Switch Ports: ");
	scanf("%d", &ports);

	printf("Printing (0/1)? ");
	scanf("%d", &printing);

	struct sw *s = switch_new(ports, ports);

	int i;
	for (i = 0; i < test_no; i++) {
		if (printing) {
			printf("\n\nTEST #%d\n", i + 1);
			switch_print(s, stdout);
		}
		switch_process(s);
		int in = rand() % ports;
		int out = rand() % ports;
		switch_put_in_queue(s, in, out, 1);
		switch_next_matching(s);
	}

	printf("%g\n", (double) s->throughput / test_no);
}

