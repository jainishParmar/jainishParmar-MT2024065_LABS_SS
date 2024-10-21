//jainish parmar
//MT2024065
//Write a program to find out total number of directories on the pwd.    execute ls -l | grep ^d | wc ? Use only dup2.


#include <unistd.h>    
#include <sys/types.h> 
#include <stdio.h>    

void main()
{
    int pipeCmdOneToTwo[2], pipeCmdTwoToThree[2]; 
    int pipeOneStatus, pipeTwoStatus;

    pid_t childOne, childTwo;

    pipeOneStatus = pipe(pipeCmdOneToTwo);
    pipeTwoStatus = pipe(pipeCmdTwoToThree);

    if (pipeOneStatus == -1 || pipeTwoStatus==-1)
        perror("Error while creating the pipe!");
    else
    {
        childOne = fork();
        if (childOne == -1)
            perror("Error while creating first child!");
        else if (childOne == 0)
        {
            close(pipeCmdTwoToThree[1]); 
            close(pipeCmdOneToTwo[0]);
            close(pipeCmdOneToTwo[1]);

            close(STDIN_FILENO);
            dup2(pipeCmdTwoToThree[0], STDIN_FILENO);

            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            childTwo = fork();

            if (childTwo == -1)
                perror("Error while creating second child!");
            else if (childTwo == 0)
            {
              

                close(pipeCmdOneToTwo[1]); 
                close(pipeCmdTwoToThree[0]);
                close(STDIN_FILENO);
                dup2(pipeCmdOneToTwo[0], STDIN_FILENO);
                close(STDOUT_FILENO);
                dup2(pipeCmdTwoToThree[1], STDOUT_FILENO);

                execl("/usr/bin/grep", "grep ^d", "^d", NULL);
            }
            else
            {
               
                close(pipeCmdOneToTwo[0]); 
                close(pipeCmdTwoToThree[1]);
                close(pipeCmdTwoToThree[0]);
                close(STDOUT_FILENO);  
                dup2(pipeCmdOneToTwo[1], STDOUT_FILENO);

                execl("/usr/bin/ls", "ls ", "-l", NULL);
            }
        }
    }
}