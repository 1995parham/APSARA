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
#include "switch.h"
#include "matching.h"

int main(int argc, char *argv[])
{
	struct sw *s = switch_new(4, 4);
	switch_print(s, stdout);
}

