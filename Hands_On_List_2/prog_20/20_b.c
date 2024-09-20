#include <sys/types.h> // Import for `open`
#include <sys/stat.h>  // Import for `open`
#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `read`
#include <stdio.h>     // Import for `perror` & `printf`

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