//Jainish Parmar
//MT2024065
/*
18. Write a program to perform Record locking.    a. Implement write lock    b. Implement read lock Create three records in a file. Whenever you access a particular record, first lock it then modify/access 
to avoid race condition.
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int fd = open("a.txt", O_RDONLY);
    struct flock rdlock = {F_RDLCK, SEEK_SET, 0, 34, getpid()};
    int id;
    printf("Enter record id:");
    scanf("%d", &id);
    switch (id)
    {
    case 1:
        /* code */
        rdlock.l_start = 0;
        break;
    case 2:
        /* code */
        rdlock.l_start = 17;
        break;
    case 3:
        /* code */
        rdlock.l_start = 34;
        break;
    default:
        perror("invalid choise of record!!!");
        return 0;
    }
    fcntl(fd, F_SETLKW, &rdlock);
    printf("record %d id locked Enter to unlock it\n", id);
    getchar();
    getchar();
    rdlock.l_type = F_ULOCK;
    fcntl(fd, F_SETLKW, &rdlock);
    printf("record is unlocked\n");
    return 0;
}