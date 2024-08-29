// jainish parmar
// MT2024065
/*
9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

int main()
{

    int status;
    struct stat statbuf;
    status = stat("../prog_8/a.txt", &statbuf);
    if (status == -1)
    {
        perror("Error while executing the file!");
    }
    else
    {
        printf("Inode -> %ld\n", statbuf.st_ino);
        printf("Number of hardlinks -> %ld\n", statbuf.st_nlink);
        printf("UID -> %d\n", statbuf.st_uid);
        printf("GID -> %d\n", statbuf.st_gid);
        printf("Size -> %ld\n", statbuf.st_size);
        printf("Block Size -> %ld\n", statbuf.st_blksize);
        printf("Number of Blocks -> %ld\n", statbuf.st_blocks);
        printf("Time of last access -> %s", ctime(&statbuf.st_atim.tv_sec));
        printf("Time of last modification -> %s", ctime(&statbuf.st_mtim.tv_sec));
        printf("Time of last change -> %s", ctime(&statbuf.st_ctim.tv_sec));
    }

    return 0;
}

/*

jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_9$ cc 9.c
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_9$ ./a.out
Inode -> 18612576
Number of hardlinks -> 1
UID -> 1000
GID -> 1000
Size -> 36
Block Size -> 4096
Number of Blocks -> 8
Time of last access -> Thu Aug 29 18:56:36 2024
Time of last modification -> Thu Aug 29 18:56:36 2024
Time of last change -> Thu Aug 29 18:56:36 2024

*/