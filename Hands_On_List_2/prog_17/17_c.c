
//jainish parmar
//MT2024065
// Write a program to execute ls -l | wc.    a. use dup    b. use dup2    c. use fcntl
#include <unistd.h>    
#include <sys/types.h> 
#include <stdio.h>    
#include<fcntl.h>
void main()
{
    int pipefd[2];  
    int pipeStatus; 
    pid_t childPid;

    pipeStatus = pipe(pipefd);

    if (pipeStatus == -1)
        perror("Error while creating the file!");
    else
    {
        childPid = fork();

        if (childPid == -1)
            perror("Error while forking child!");
        else if (childPid == 0)
        {
         
            close(STDIN_FILENO);
            fcntl(pipefd[0], F_DUPFD, STDIN_FILENO); 
            close(pipefd[1]);
            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            
            close(STDOUT_FILENO);
            fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO); 
            close(pipefd[0]);
            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
}
