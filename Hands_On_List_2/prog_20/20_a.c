
//jainish parmar
//MT2024065
//Write two programs so that both can communicate by FIFO -Use one way communication

#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>   
#include <stdio.h>    

void main()
{
    int fifoStatus;                              
    char data[] = "Sending data at warp speed!";
    int fileDescriptor;                          
    char *fifoFile = "./20-fifo";                
    int writeBytes;                             

    fifoStatus = mkfifo(fifoFile, S_IRWXU);

    if (fifoStatus == -1)
        perror("Error while creating FIFO file!");
    fileDescriptor = open(fifoFile, O_WRONLY);
    if (fileDescriptor == -1)
        perror("Error while opening FIFO file for writing");
    else
    {
        writeBytes = write(fileDescriptor, &data, sizeof(data));
        if (writeBytes == -1)
            perror("Error while writing to the file!");
        close(fileDescriptor);
    }
}