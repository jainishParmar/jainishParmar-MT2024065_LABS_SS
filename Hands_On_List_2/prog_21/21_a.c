// Question : Write two programs so that both can communicate by FIFO - Use two way communications.

#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>    
#include <unistd.h>   
#include <stdio.h>     



void main()
{
    int readBytes, writeBytes;
    int fifoOneFD, fifoTwoFD;
    char data[100];

    

    fifoOneFD = open("21-fifoOne", O_WRONLY);
    if (fifoOneFD == -1)
    {
        perror("Error while opening fifoOne");
        _exit(0);
    }

    fifoTwoFD = open("21-fifoTwo", O_RDONLY);
    if (fifoOneFD == -1)
    {
        perror("Error while opening fifoTwo");
        _exit(0);
    }

    writeBytes = write(fifoOneFD, "From 21a to 21b", 15);

    if (writeBytes == -1)
        perror("Error while writing to FIFO fifoOne!");

    close(fifoOneFD);

    readBytes = read(fifoTwoFD, &data, 100);

    if (readBytes == -1)
    {
        perror("Error while reading from FIFO fifoTwo!");
        _exit(0);
    }

    printf("Data from FIFO: %s\n", data);

    close(fifoTwoFD);
}