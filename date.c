#include "types.h"
#include "user.h"
#include "date.h"
#include "stat.h"
#include "fcntl.h"

int date();
int halt();
void periodic();
int
main(int argc, char *argv[])
{
  uint temp_second=0, count=0, limit=0;
  struct rtcdate r;
  int i;
  if(date(&r)){
    printf(2, "date failed\n");
    exit();
  }
  temp_second=r.second;
  printf(1, "%d-%d-%d %d:%d:%d\n", r.year, r.month, r.day, r.hour, r.minute, r. second);
  //halt();
  if(argc>1)
  { 
    printf(1, "argv: %d\n", atoi(argv[argc-1]));
    limit=atoi(argv[1]);
    for(i=0;r.second-temp_second<limit;i++)
    {
      if(date(&r)){
        printf(2, "date failed\n");
        exit();
      }
      if(count!=r.second-temp_second)
      	  printf(1, "Count: %d\n", count=r.second-temp_second);
    }
  }
  else
    printf(1,"Wrong command: need enter [date number]\n");
  printf(1, "%d-%d-%d %d:%d:%d\n", r.year, r.month, r.day, r.hour, r.minute, r. second);
  temp_second=r.second;
  /*printf(1, "alarmtear starting\n");
  alarm(10, periodic);
  for(i=0; i < 50*5000000;i++){
    if((i++ %5000000)==0)
      write(2, ".", 1);
  }*/
  chpr(atoi(argv[2]), atoi(argv[3]));
  cps();
  if(date(&r)){
    printf(2, "date failed\n");
    exit();
  }
  printf(1, "%d-%d-%d %d:%d:%d\n", r. year, r.month, r.day, r.hour, r.minute, r.second);
  printf(1, "Total time: %d\n", r.second-temp_second);
  exit();
}

void
periodic()
{
  printf(1, "alarm!\n");
}


