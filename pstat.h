#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

struct pstat
{
    int inuse[NPROC];
    int pid[NPROC];
    int hticks[NPROC];
    char name[NPROC][16];
    int lticks[NPROC];
    int priority;
    int state;
};

#endif