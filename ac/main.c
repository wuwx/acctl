/*
 * ============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月18日 17时30分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jianxi sun (jianxi), ycsunjane@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <signal.h>

#include "arg.h"
#include "net.h"
#include "msg.h"
#include "aphash.h"
#include "process.h"
#include "netlayer.h"
#include "resource.h"
#include "sql.h"

void ui()
{
	printf("1 system status\n");

	int num;
	while(1) {
		printf("Input num: ");
		scanf("%d", &num);

		switch(num) {
		case 1: {
			}
		}
	}
}

int main(int argc, char *argv[])
{
	sql_init(&sql);

	proc_arg(argc, argv);
	/* resource init */
	resource_init();
	/* set ac uuid, random, md5sum */
	ac_init();
	/* init ap hash table */
	hash_init();
	/* start message travel thread */
	message_travel_init();
	/* start recv message */
	net_init();

	ui();
	return 0;
}
