//jainish parmar
//MT2024065
//. Write a separate program using signal system call to catch the following signals.    a. SIGSEGV    b. SIGINT    c. SIGFPE    d. SIGALRM (use alarm system call)    e. SIGALRM (use setitimer system call)    f. SIGVTALRM (use setitimer system call)    g. SIGPROF (use setitimer system call)

#include <signal.h> 
#include <stdio.h>  
#include <unistd.h> 

void callback()
{
    printf("Signal SIGSEGV has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; 

    signalStatus = signal(SIGSEGV, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGSEGV); 
        
}