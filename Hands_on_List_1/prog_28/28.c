// jainish parmar
// MT2024065
// 28. Write a program to get maximum and minimum real time priority.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sched.h>
int main()
{

    int maxi, mini;

    maxi = sched_get_priority_max(SCHED_FIFO);
    if (maxi == -1)
        perror("err\n");
    else
        printf("The max priority with FIFO Scheduling Policy is : %d\n", maxi);

    mini = sched_get_priority_min(SCHED_FIFO);
    if (mini == -1)
        perror("err\n");
    else
        printf("The min priority with FIFO Scheduling Policy is : %d\n", mini);

    return 0;
}

/*
The max priority with FIFO Scheduling Policy is : 99
The min priority with FIFO Scheduling Policy is : 1
*/