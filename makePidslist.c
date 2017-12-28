#include "types.h"
#include "user.h"
#include "stat.h"
#include "pstat.h"

int main()
{
    printf(1, "Process schedling:\n");
 printf(1, "Slot\tPID\tHIgh\tLow\tPriority\tState\n");
 struct pstat st;
 getAllPids(&st);
 for(int i = 0;i<NPROC;i++)
 {
     if(st.inuse[i])
     {
        printf(1, "%d\t%d\t%d\t%d\t%s\t%d\t", i, st.pid[i], st.hticks[i], st.lticks[i], st.name, st.priority);
        switch(st.state)
        {
            case 0:
                printf(1,"%s", "Unused");
                break;
            case 1:
                printf(1,"%s", "Embryo");
                break;
            case 2:
                printf(1,"%s", "Sleeping");
                break;
            case 3:
                printf(1,"%s", "Runnable");
                break;
            case 4:
                printf(1,"%s", "Running");
                break;
            case 5:
                printf(1,"%s", "Zombie");
                break;

        }
        printf(1, "\n");
     }
 }
 exit();
}
