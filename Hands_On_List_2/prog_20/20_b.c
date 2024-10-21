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
    int fileDescriptor;           
    char *fifoFile = "./20-fifo"; 
    int readBytes;                
    char data[100];              

    fileDescriptor = open(fifoFile, O_RDONLY);

    if (fileDescriptor == -1)
        perror("Error while opening the FIFO file!");
    else
    {
        readBytes = read(fileDescriptor, data, 100);
        if (readBytes == -1)
            perror("Error while reading from the FIFO file!");
        else
        {
            printf("Read bytes : %d\n", readBytes);
            printf("Data from the FIFO file - %s\n", data);
        }
        close(fileDescriptor);
    }
}