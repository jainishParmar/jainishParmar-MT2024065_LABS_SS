// jainish parmar
// MT2024065
// Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,  SCHED_RR).

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/types.h> 

int main()
{
    int currentPolicy;
    pid_t pid;
    pid = getpid();
    currentPolicy = sched_getscheduler(pid);
    struct sched_param priority;
    priority.sched_priority = 10;
    switch (currentPolicy)
    {
        case SCHED_FIFO:
            printf("Current policy is FIFO\n");
            sched_setscheduler(pid, SCHED_RR, &priority);
            currentPolicy = sched_getscheduler(pid);
            printf("Current policy is %d\n", currentPolicy);
             switch (currentPolicy)
            {
            case SCHED_FIFO:
                printf("fifo\n");
                break;
            case SCHED_RR:
                printf("rr\n");
                break;
            case SCHED_OTHER:
                printf("other\n");
                break;
            
            default:
                break;
            }
            break;
        case SCHED_RR:
            printf("Current policy is RR\n");
            sched_setscheduler(pid, SCHED_FIFO, &priority);
            currentPolicy = sched_getscheduler(pid);
            printf("Current policy is %d\n", currentPolicy);
             switch (currentPolicy)
            {
            case SCHED_FIFO:
                printf("fifo\n");
                break;
            case SCHED_RR:
                printf("rr\n");
                break;
            case SCHED_OTHER:
                printf("other\n");
                break;
            
            default:
                break;
            }
            break;
        case SCHED_OTHER:
            printf("Current policy is OTHER\n");
            sched_setscheduler(pid, SCHED_RR, &priority);
            currentPolicy = sched_getscheduler(pid);
            printf("Current policy is %d\n", currentPolicy);
            switch (currentPolicy)
            {
            case SCHED_FIFO:
                printf("fifo\n");
                break;
            case SCHED_RR:
                printf("rr\n");
                break;
            case SCHED_OTHER:
                printf("other\n");
                break;
            
            default:
                break;
            }
            break;
        default:
            perror("Error while getting current policy\n");
    }

    return 0;
}

/*
Current policy is OTHER
Current policy is 0
*/