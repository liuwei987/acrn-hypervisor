/*************************************************************************
    > File Name: devicemodel/include/dm_ftrace.h
    > Author:		
    > Mail:		
    > Created Time: 2019年01月10日 星期四 08时32分41秒
 ************************************************************************/

#include <sys/types.h>

int ftrace_shot(char *);
int ftrace_enable(char *);
int ftrace_switch(char *);
int ftrace_pid(pid_t);
int ftrace_set(char *);

