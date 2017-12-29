#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int
main(int argc, char*argv[])
{
  if(argc<2)
  {
    printf(2, "Need: maxpriority\n");
    exit();
  } 
  printf(1, "Maxpriority: %d\n", atoi(argv[1]));
  printf(1, "Awake success.\n");
  priawake(atoi(argv[1]));
  exit();
}
