// jainish parmar
// MT2024065
// Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{

    int fd1 = creat("a.txt", S_IRWXU);
    if (fd1 == -1)
    {
        perror("error");
    }
    else
    {
        printf("%d\n", fd1);
    }
    int fd2 = creat("b.txt", S_IRWXU);
    if (fd2 == -1)
    {
        perror("error");
    }
    else
    {

        printf("%d\n", fd2);
    }
    int fd3 = creat("c.txt", S_IRWXU);
    if (fd3 == -1)
    {
        perror("error");
    }
    else
    {
        printf("%d\n", fd3);
    }
    int fd4 = creat("d.txt", S_IRWXU);
    if (fd4 = -1)
    {
        perror("error");
    }
    else
    {
        printf("%d\n", fd4);
    }
    int fd5 = creat("f.txt", S_IRWXU);
    if (fd5 == -1)
    {
        perror("error");
    }
    else
    {

        printf("%d\n", fd5);
    }
    while (1)
    {
    }

    return 0;
}

/*


jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/proc/26008/fd$ ls
0  1  103  2  3  37  38  39  4  40  42  5  6  7
*/