//jainish parmar
//MT2024065
/*
. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to 
the parent process from the child process.

*/

#include <sys/types.h> 
#include <signal.h>    
#include <unistd.h>    
#include <stdio.h>
void main()
{
    pid_t childPid, parentPid;
    int killStatus; 

    childPid = fork();

    if (childPid == -1)
        perror("Error while creating child!");
    else if (!childPid)
    {
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(10);

        killStatus = kill(getppid(), SIGKILL);

        if (!killStatus)
        {
            printf("Successfully killed parent!\n");
            sleep(10);
            printf("Child now exiting!\n");
        }
        else
            perror("Error while killing parent!");
    }
    else
    {
        while (1){
        printf("parent execcuting....\n");}
    }
}