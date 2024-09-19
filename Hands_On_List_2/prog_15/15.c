#include <unistd.h>    
#include <sys/types.h> 
#include <stdio.h>     

void main()
{
    pid_t childPid;
    int pipefd[2];             
    int pipeStatus;            
    int readBytes, writeBytes; 

    char *writeBuffer = "data from parent", *readBuffer;

    pipeStatus = pipe(pipefd);

    if (pipeStatus == -1)
        perror("Error while creating pipe!");
    else
    {
        printf("Pipe created successfully\n");
        childPid = fork();
        if (childPid == -1)
            perror("Error whiling forking new child!");
        else if (childPid == 0)
        {
            
            readBytes = read(pipefd[0], &readBuffer, sizeof(writeBuffer));
            if (readBytes == -1)
                perror("Error while reading from pipe!\n");
            else
                printf("Data from parent: %s\n", readBuffer);
        }
        else
        {
            sleep(5);
            writeBytes = write(pipefd[1], &writeBuffer, sizeof(writeBuffer));
            if (writeBytes == -1)
                perror("Error while writing to pipe!");
        }
    }
}