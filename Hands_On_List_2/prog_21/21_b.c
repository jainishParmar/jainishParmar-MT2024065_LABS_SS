
//jainish parmar
//MT2024065
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
 
    fifoOneFD = open("21-fifoOne", O_RDONLY);
    if (fifoOneFD == -1)
    {
        perror("Error while opening fifoOne");
        _exit(0);
    }
    fifoTwoFD = open("21-fifoTwo", O_WRONLY);
    if (fifoOneFD == -1)
    {
        perror("Error while opening fifoTwo");
        _exit(0);
    }

    writeBytes = write(fifoTwoFD, "From 21b to 21a", 15);
    if (writeBytes == -1)
        perror("Error while writing to FIFO fifoOne!");

    close(fifoTwoFD);
    readBytes = read(fifoOneFD, &data, 100);

    if (readBytes == -1)
    {
        perror("Error while reading from FIFO fifoOne!");
        _exit(0);
    }

    printf("Data from FIFO: %s\n", data);
    close(fifoOneFD);
}