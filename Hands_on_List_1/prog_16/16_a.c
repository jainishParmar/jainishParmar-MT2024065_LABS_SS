// jainish parmar
// MT2024065
// 16. Write a program to perform mandatory locking.    a. Implement write lock    b. Implement read lock

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char* argv[])
{
    char *filename;
    struct flock lock, lockStatus;
    int fd;

    if (argc != 2)
        printf("Pass the file name to be locked as the argument!");
    else
    {
        filename = argv[1];
        lock.l_type = F_WRLCK;    
        lock.l_whence = SEEK_SET; 
        lock.l_start = 0;         
        lock.l_len = 0;           
        lock.l_pid = getpid();
        lockStatus = lock;
        fd = open(filename, O_RDWR);
        fcntl(fd, F_GETLK, &lockStatus);
        if (lockStatus.l_type == F_WRLCK) 
            printf("File already locked for writing\n");
        else if (lockStatus.l_type == F_RDLCK) 
            printf("File already locked for reading\n");
        else
        {
            fcntl(fd, F_SETLK, &lock);
            printf("File is now locked for writing\n");
        }
        sleep(50);
        return 0;
    }
}

/*
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_16$ cc 16.c
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_16$ ./a.out a.txt
File is now locked for writing

*/