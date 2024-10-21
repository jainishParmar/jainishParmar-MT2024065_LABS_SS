//jainish parmar
//MT2024065
/*
Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
*/

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
void callback()
{
    printf("Received SIGSTOP");
     _exit(0);
}
void main()
{
    printf("%d\n",getpid());
    __sighandler_t signalStatus; 

    signalStatus = signal(SIGSTOP, (void *)callback);
    if (signalStatus == SIG_ERR)
    {
        perror("Error while assigning signal handler");
    }
    sleep(15);
}

