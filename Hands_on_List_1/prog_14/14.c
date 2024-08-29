// jainish parmar
// MT2024065
// 14 Write a program to find the type of a file.
// a. Input should be taken from command line.
// b. program should be able to identify any type of a file.

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    struct stat statbuf;
    int fd;
    if (argc != 2)
        printf("Pass the name of the file as the argument");
    else
    {
        fd = open(argv[1], O_RDONLY);
        fstat(fd, &statbuf);

        if (S_ISDIR(statbuf.st_mode))
            write(STDOUT_FILENO, "Directory File\n", 15);

        else if (S_ISCHR(statbuf.st_mode))
            write(STDOUT_FILENO, "Character File\n", 15);

        else if (S_ISBLK(statbuf.st_mode))
            write(STDOUT_FILENO, "Block File\n", 11);

        else if (S_ISFIFO(statbuf.st_mode))
            write(STDOUT_FILENO, "FIFO File\n", 10);

        else if (S_ISLNK(statbuf.st_mode))
            write(STDOUT_FILENO, "Symbolic Link File\n", 19);

        else if (S_ISREG(statbuf.st_mode))
            write(STDOUT_FILENO, "Regular File\n", 13);

        else if (S_ISSOCK(statbuf.st_mode))
            write(STDOUT_FILENO, "Socket\n", 7);

        else
            write(STDOUT_FILENO, "Error\n", 6);
    }
    return 0;
}

/*
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_14$ ./a.out ./a.txt
Regular File
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_14$ ./a.out a.txt
Regular File
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_14$ ./a.out ../prog_13
Directory File
 */