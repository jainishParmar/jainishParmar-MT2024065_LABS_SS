// jainish parmar
// MT2024065
/*
10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    char *filename = "a.txt";
    int fd;
    int offset;
    int writeByteCount;
    fd = open(filename, O_RDWR|O_CREAT);

    if (fd == -1)
        perror("Error while opening file! ");
    else
    {
        offset = lseek(fd, 10, SEEK_SET); // Move forward 10 bytes from start of the file
        writeByteCount = write(fd, "ABCDEFGHIJ", 10);
        if (writeByteCount == -1)
        {
            perror("Error while writing to the file!");
            _exit(1);
        }

        offset = lseek(fd, 10, SEEK_CUR); // Move forward 10 bytes from the current position in the file
        writeByteCount = write(fd, "ABCDEFGHIJ", 10);
        if (writeByteCount == -1)
        {
            perror("Error while writing to the file!");
            _exit(1);
        }

        printf("Return value of lseek: %d\n", offset);
        close(fd);
    }
    return 0;
}

/*
ainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_10$ cc 10.c
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_10$ ./a.out
Return value of lseek: 30
          ABCDEFGHIJ          ABCDEFGHIJ
*/