#include <unistd.h> 
#include <stdio.h>  

void main()
{
    int pipefd[2];               
    char *writeBuffer = "creating pipe simulation!!"; 
    char *readBuffer;
    int pipeStatus;            
    int readBytes, writeBytes; 
    pipeStatus = pipe(pipefd);
    if (pipeStatus == -1)
        perror("Error while creating the pipe! ");
    else
    {
        printf("Writing to the pipe!\n");
        writeBytes = write(pipefd[1], &writeBuffer, sizeof(writeBuffer));
        if (writeBytes == -1)
            perror("Error while writing to pipe!");
        else
        {
            printf("Now reading from the pipe!\n");
            readBytes = read(pipefd[0], &readBuffer, writeBytes);
            if (readBytes == -1)
                perror("Error while reading from pipe!");
            else
                printf("Data from pipe: %s\n", readBuffer);
        }
    }
}