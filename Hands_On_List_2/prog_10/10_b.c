/*
 Write a separate program using sigaction system call to catch the following signals.    a. SIGSEGV    b. SIGINT c. SIGFPE
*/
#define _XOPEN_SOURCE 700

#include <signal.h> 
#include <stdio.h> 
#include <unistd.h> 

void signalHandler(int signalNumber)
{
    printf("Caught signal sigint (%d)\n", signalNumber);
    _exit(0);
}

void main()
{
    int status; 
    struct sigaction action;
    char *a;

    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
    {
        sleep(5);
    }
}