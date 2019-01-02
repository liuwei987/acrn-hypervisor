/*
 * Copyright (C) 2018 Intel Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _DM_PROFILING_H_
#define _DM_PROFILING_H_

int open_kmsg(void);
int write_kmsg(const char *log, ...);
int close_kmsg(void);

#endif /* _DM_PROFILING_H_ */
