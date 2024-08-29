//jainish parmar
//MT2024065
//12. Write a program to find out the opening mode of a file. Use fcntl.

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){


    char* filename="a.txt";

    int fd = open(filename, O_RDONLY);
    int fmode = fcntl(fd, F_GETFL);
    printf("%d\n", fmode);

    int accessMode = fmode & O_ACCMODE;
    printf("%d\n", accessMode);

    switch (accessMode)
    {
    case O_RDWR:
        printf("O_RDWR");
        break;
    case O_WRONLY:
        printf("O_WRONLY");
        break;
    case O_RDONLY:
        printf("O_RDONLY");
        break;
    default:
        break;
    }
    
    return 0;
}

/*
32768
0
O_RDONLY

*/