#include "types.h"
#include "stat.h"
#include "date.h"
#include "user.h"
#include "fcntl.h"
int date();
int
main(int argc, char *argv[])
{
  if(argc==3)
  {
    uint count=0, limit=0, cursecond=0;
    struct rtcdate r, temp;
    int i;
    if(date(&r)){
      printf(2, "date failed\n");
      exit();
    }
    temp=r;
    cursecond=r.second;
    printf(1, "%d-%d-%d %d:%d:%d\n", r.year, r.month, r.day, r.hour, r.minute, r.second);
    limit=atoi(argv[1]);
    printf(1, "Prisleep %d\n", atoi(argv[2]));
    prisleep(atoi(argv[2]));
    cps();
    for(i=0;cursecond-temp.second<limit;i++)
    {
      if(date(&r))
      {
        printf(2, "date failed\n");
        exit();
      }
      cursecond=r.second;
      if(r.minute>temp.minute)
         cursecond+=60;
      if(count!=cursecond-temp.second)
        printf(1, "Count: %d\n", count=cursecond-temp.second);
    }    
    printf(1, "%d-%d-%d %d:%d:%d\n", r.year, r.month, r.day, r.hour, r.minute, r.second);

  }
  else
    printf(2, "Need timerx second prisleep/priawake maxpri\n");
  printf(1, "Priawake %d\n", atoi(argv[2]));
  priawake(atoi(argv[2]));
  cps();
  exit();




}

