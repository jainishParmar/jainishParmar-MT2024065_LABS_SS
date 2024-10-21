//jainish parmar
//MT2024065
/*
1.  Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second        
a. ITIMER_REAL        b. ITIMER_VIRTUAL        c. ITIMER_PROF
*/

#include <sys/time.h> 
#include <signal.h>   
#include <unistd.h>   
#include <stdio.h>    

void main(int argc, char *argv[])
{
    int timerStatus; 

    struct itimerval timer;

    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timerStatus = setitimer(ITIMER_VIRTUAL, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");

    while(1);
}