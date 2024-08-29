// Question : Write a program to simulate online ticket reservations. Implement a write lock.  Write a program to open a file, store a ticket number, and exit.  Write a separate program, to open the file,  implement write lock, read the ticket number, increment the number, and print the new ticket number then close the file

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    char *ticketFile = "a.txt";
    int fileDescriptor, fcntlStatus;
    ssize_t readBytes, writeBytes;
    off_t lseekOffset;
    int buffer;
    struct flock ticketLock;

    fileDescriptor = open(ticketFile, O_CREAT | O_RDWR, S_IRWXU);

    if (fileDescriptor == -1)
        perror("Error while opening the file!");
    else
    {
        ticketLock.l_type = F_WRLCK;
        ticketLock.l_pid = getpid();
        ticketLock.l_whence = SEEK_SET;
        ticketLock.l_len = 0;
        ticketLock.l_start = 0;

        fcntlStatus = fcntl(fileDescriptor, F_GETLK, &ticketLock);

        if (fcntlStatus == -1)
            perror("Error while getting lock status!");
        else
        {
            switch (ticketLock.l_type)
            {
            case F_WRLCK:
                printf("The ticket File %s is already locked for writing!\n", ticketFile);
                break;
            case F_RDLCK:
                printf("The ticket File %s is already locked for reading!\n", ticketFile);
                break;
            default:
                ticketLock.l_type = F_WRLCK;
                fcntlStatus = fcntl(fileDescriptor, F_SETLKW, &ticketLock);
                if (fcntlStatus == -1)
                    perror("Error while locking the ticket file!");
                else
                {
                    readBytes = read(fileDescriptor, &buffer, sizeof(int));
                    if (readBytes == -1)
                        perror("Error while reading ticket!");
                    else if (readBytes == 0)
                    {
                        buffer = 1;
                        writeBytes = write(fileDescriptor, &buffer, sizeof(int));
                        if (writeBytes == -1)
                            perror("Error while writing to ticket!");
                        else
                            printf("Your ticket number is %d\n", buffer);
                    }
                    else
                    {
                        lseekOffset = lseek(fileDescriptor, 0, SEEK_SET);
                        if (lseekOffset == -1)
                            perror("Error while seeking!");
                        else
                        {
                            buffer += 1;
                            writeBytes = write(fileDescriptor, &buffer, sizeof(int));
                            printf("Your ticket number is: %d\n", buffer);
                        }
                    }
                    ticketLock.l_type = F_UNLCK;
                    fcntlStatus = fcntl(fileDescriptor, F_SETLKW, &ticketLock);
                    if (fcntlStatus == -1)
                        perror("Error releasing lock!");
                    else
                        printf("Done!\n");
                }
            }
        }
        close(fileDescriptor);
    }
}