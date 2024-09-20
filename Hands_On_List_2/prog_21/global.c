#include <errno.h>
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>   
#include <unistd.h>   
#include <stdio.h>    

char *fifoOneName = "./21-fifoOne";
char *fifoTwoName = "./21-fifoTwo";

void main()
{
    int fifoOneStatus, fifoTwoStatus; // Determines the success of the `mkfifo` call

    fifoOneStatus = mkfifo(fifoOneName, S_IRWXU);
    if (!(errno == EEXIST || fifoOneStatus != -1))
        perror("Error while creating FIFO file fifoOne");

    fifoTwoStatus = mkfifo(fifoTwoName, S_IRWXU);
    if (!(errno == EEXIST || fifoTwoStatus != -1))
        perror("Error while creating FIFO file fifoTwo");
}