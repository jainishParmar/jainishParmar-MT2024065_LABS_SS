

//jainish parmar
//MT2024065
// Write a program to execute ls -l | wc.    a. use dup    b. use dup2    c. use fcntl
#include <unistd.h>    
#include <sys/types.h> 
#include <stdio.h>    

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
            dup2(pipefd[0], STDIN_FILENO); 
            close(pipefd[1]);
            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            
            close(STDOUT_FILENO);
            dup2(pipefd[1], STDOUT_FILENO); 
            close(pipefd[0]);
            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
}


