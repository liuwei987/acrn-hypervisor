/*
 * Copyright (C) 2020 Intel Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MISC_CFG_H
#define MISC_CFG_H

#define SOS_ROOTFS		"root=/dev/mmcblk0p2 "
#define SOS_CONSOLE		"console=ttyS0 "
#define SOS_COM1_BASE		0x3F8U
#define SOS_COM1_IRQ		3U
#define SOS_COM2_BASE		0x2E8U
#define SOS_COM2_IRQ		4U

#define SOS_BOOTARGS_DIFF	"rw " \
				"rootwait "	\
				"console=tty0 "	\
				"consoleblank=0 "	\
				"no_timer_check "	\
				"quiet "	\
				"loglevel=3 "	\
				"i915.nuclear_pageflip=1"

#define CLOS_MASK_0			0xfffU
#define CLOS_MASK_1			0xfffU
#define CLOS_MASK_2			0xfffU
#define CLOS_MASK_3			0xfffU
#define CLOS_MASK_4			0xfffU
#define CLOS_MASK_5			0xfffU
#define CLOS_MASK_6			0xfffU
#define CLOS_MASK_7			0xfffU
#define CLOS_MASK_8			0xfffU
#define CLOS_MASK_9			0xfffU
#define CLOS_MASK_10			0xfffU
#define CLOS_MASK_11			0xfffU
#define CLOS_MASK_12			0xfffU
#define CLOS_MASK_13			0xfffU
#define CLOS_MASK_14			0xfffU
#define CLOS_MASK_15			0xfffU

#endif /* MISC_CFG_H */
