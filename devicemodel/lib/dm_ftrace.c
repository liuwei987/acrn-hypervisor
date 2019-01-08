/*************************************************************************
    > File Name: devicemodel/lib/dm_ftrace.c
    > Author:		
    > Mail:		
    > Created Time: 2019年01月10日 星期四 08时30分47秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "dm_ftrace.h"

#define TACE_EN "/proc/sys/kernel/ftrace_enable"
#define TACE_ON "/sys/kernel/debug/tracing/tracing_on"
#define TACE_ER "/sys/kernel/debug/tracing/current_tracer"
#define TACE_ST "/sys/kernel/debug/tracing/snapshot"
#define TACE_EN "/sys/kernel/debug/tracing/set_ftrace_pid"
//#define TACE_EN "/sys/kernel/debug/tracing/available_tracer"


int ftrace_set(char *cmd)
{
	char buf[20];
	int err, cnt, fd;

	fd = open(TACE_ER, O_RDWR | O_TRUNC);
	if (fd < 0) {
		perror("Open"TACE_ER);
	}

	printf("In cmd= %s, len=%d\n", cmd, strlen(cmd));
	// write the settings
	cnt = write(fd, cmd, strlen(cmd)); 
	if (cnt < 0) {
		perr("Write"TACE_ER);
		goto err_set;
	}

	// read back settings
	err = read(fd, buf, cnt);
	if (err < 0) {
		perr("Read"TACE_ER);
		goto err_set;

	}
	printf("%s read back: %s", __func__, buf);

err_set:
	close(fd);
	return -1;
}

int ftrace_switch(char *cmd)
{
	char buf[20];
	int err, cnt, fd;

	fd = open(TACE_ON, O_RDWR | O_TRUNC);
	if (fd < 0) {
		perror("Open"TACE_ON);
	}

	printf("In cmd= %s, len=%d\n", cmd, strlen(cmd));
	// write the settings
	cnt = write(fd, cmd, strlen(cmd)); 
	if (cnt < 0) {
		perr("Write"TACE_ON);
		goto err_on;
	}

	// read back settings
	err = read(fd, buf, cnt);
	if (err < 0) {
		perr("Read"TACE_ON);
		goto err_on;

	}
	printf("%s read back: %s", __func__, buf);

err_on:
	close(fd);
	return -1;
}

int ftrace_enabled(char *cmd)
{
	char buf[20];
	int err, cnt, fd;

	fd = open(TACE_ER, O_RDWR | O_TRUNC);
	if (fd < 0) {
		perror("Open"TACE_ER);
	}

	printf("In cmd= %s, len=%d\n", cmd, strlen(cmd));
	// write the settings
	cnt = write(fd, cmd, strlen(cmd)); 
	if (cnt < 0) {
		perr("Write"TACE_ER);
		goto err_set;
	}

	// read back settings
	err = read(fd, buf, cnt);
	if (err < 0) {
		perr("Read"TACE_ER);
		goto err_set;

	}
	printf("%s read back: %s", __func__, buf);

err_set:
	close(fd);
	return -1;
}
