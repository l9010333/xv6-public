#include "types.h"
#include "user.h"

int main(void)
{
    int childpid = fork();
    if(childpid<0)
    printf(1, "fork error!\n");
    else if(childpid >0)
    {
        printf(1, "this is parent, pid is %d, child id is %d\n", getpid(), childpid);
        wait();
    }
    else
    {
        printf(1, "this is child, pid is %d, parent id is %d\n", getpid(), getppid());
    }
}