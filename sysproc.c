#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "pstat.h"


int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_getppid(void)
{
  return myproc()->parent->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
int
sys_halt(void)
{
	//char *p = "Shutdown";
	//for (; *p; p++)
		//outb(0x8900, *p);
	cprintf("shutdown\n");
	outw(0xB004, 0x0 | 0x2000 );
	return 0;
}
int
sys_alarm(void)
{
  int ticks;
  void (*handler)();

  if(argint(0, &ticks)<0)
	return -1;
  if(argptr(1, (char**)&handler, 1)<0)
	return -1;
  myproc()->alarmticks = ticks;
  myproc()->alarmhandler =handler;
  return 0;
}

int
sys_date(void)
{
  struct rtcdate* date;
  argptr(0, (void*)(&date), sizeof(*date));
  cmostime(date);
  return 0;
}



int
sys_getAllPids(void)
{
  
  struct pstat *st;
  if (argptr(0, (void*)&st, sizeof(*st))<0)
    return -1;
  for(int i = 0;i<NPROC;i++)
  {
    st->inuse[i] = pstat.inuse[i],
    st->pid[i] = pstat.pid[i],
    st->name[i][0] = pstat.name[i][0],
    st->name[i][1] = pstat.name[i][1],
    st->name[i][2] = pstat.name[i][2],
    st->hticks[i] = pstat.hticks[i],
    st->lticks[i] = pstat.lticks[i];
    st->priority = pstat.priority;
    st->state = pstat.state;
  }

  return 0;
}

int
sys_cps(void)
{
  return cps();
}

int
sys_chpr(void)
{
  int pid, pr;
  if(argint(0,&pid) < 0)
    return -1;
  if(argint(1,&pr) < 0)
    return -1;

  return chpr(pid,pr);
}
int
sys_prisleep(void)
{
 int curmaxpri;
 if(argint(0, &curmaxpri)<0)
   return -1;
 return prisleep(curmaxpri);

}
int
sys_priawake(void)
{
 int curmaxpri;
 if(argint(0, &curmaxpri)<0)
   return -1;
 return priawake(curmaxpri);
}
int
sys_timerx(void)
{
  //int curmaxpri;
  struct rtcdate *date;
  if(argptr(0, (void*)(&date), sizeof(*date))<0)
    return -1;
  //if(argint(1, &curmaxpri)<0)
    //return -1;
  cmostime(date);
  return 0;
}
