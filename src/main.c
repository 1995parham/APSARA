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
#include <string.h>

#include "switch.h"
#include "matching.h"

int main(int argc, char *argv[])
{
	int test_no, ports, load;
	char path[1024];
	FILE *log_file;
	int packet_no;

	printf("Simulation Times: ");
	scanf("%d", &test_no);
	
	printf("Switch Ports: ");
	scanf("%d", &ports);

	printf("Load (0 to 100): ");
	scanf("%d", &load);
	if (load < 0 || load > 100)
		load = 80;

	printf("LogFile (empty for not logging)? ");
	getchar();
	fgets(path, 1024, stdin);
	if (*path) {
		path[strlen(path) - 1] = 0;
		log_file = fopen(path, "w");
	}

	packet_no = 0;

	struct sw *s = switch_new(ports);

	int i, in;

	for (i = 0; i < test_no; i++) {
		if (log_file) {
			fprintf(log_file, "\n\nFRAME #%d\n", i + 1);
			switch_print(s, log_file);
		}
		for (in = 0; in < ports; in++) {
			if (rand() % 100 < load) {
				switch_put_in_queue(s, in, rand() % ports, 1);
				packet_no++;
			}
		}
		switch_next_matching(s);
		switch_process(s);
	}

	printf("%g\n", (double) s->throughput / packet_no);
}

