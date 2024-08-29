// jainish parmar
// MT2024065

/*
11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.    a. use dup    b. use dup2    c. use fcntl


*/
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    char *filename = "c.txt";
    int fd, dfd;
    int flag;

    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
    {
        perror("Error while opening file");
    }
    else
    {
        dfd = fcntl(fd,F_DUPFD, 13);
        if (dfd == -1)
        {
        }
        else
        {
            flag = write(fd, "Using original FD\n", 18);
            if (flag == -1)
            {
                perror("Error while writing file using original FD");
            }
            flag = write(dfd, "Using duplicate FD\n", 19);
            if (flag == -1)
            {
                perror("Error while writing file using duplicate FD");
            }
        }

        close(fd);
        close(dfd);
        return 0;
    }
}

/*

intially present content
Using original FD
Using duplicate FD

*/