/*
 * Copyright (C) 2018 Intel Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include "dm_profiling.h"

#define DM_BUF    4096
#define KERN_NODE "/dev/kmsg"

int fd_kmsg;
char dm_buf[DM_BUF];

int open_kmsg(void)
{
	int fd;

	/* open /dev/kmsg */
	fd = open(KERN_NODE, O_RDWR | O_APPEND | O_NONBLOCK);
	if (fd < 0) {
		perror("open_kmsg");
		return fd;
	}

	fd_kmsg = fd;
	return fd;
}

int write_kmsg(const char *fmt, ...)
{
	int write_cnt;
	va_list args;

	va_start(args, fmt);
	vsnprintf(dm_buf, DM_BUF, fmt, args);
	va_end(args);

	open_kmsg();

	/* write the fmt to the /dev/kmsg */
	write_cnt = write(fd_kmsg, dm_buf, strlen(dm_buf));
	if (write_cnt < 0) {
		perror("write_kmsg");
		close_kmsg();
		return -1;
	}

	close_kmsg();
	return write_cnt;
}

int close_kmsg(void)
{
	int err;

	/* close /dev/kmsg */
	err = close(fd_kmsg);
	if (err == -1) {
		perror("close_kmsg");
		return err;
	}

	return 0;
}
