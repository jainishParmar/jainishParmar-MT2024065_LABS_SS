
// jainish parmar
// MT2024065
// 7. Write a program to copy file1 into file2 ($cp file1 file2).

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{

    char *source_file = "a.txt";
    char *dest_file = "b.txt";
    int sfid, dfid;
    sfid = open(source_file, O_RDONLY);
    dfid = open(dest_file, O_CREAT | O_RDWR, S_IRWXU);
    if (sfid == -1 || dfid == -1)
    {
        perror("error");
        _exit(1);
    }
    char buff;
    int read_flag;
    int write_flag;
    while (read(sfid, &buff, 1))
    {
        write_flag = write(dfid, &buff, 1);
        if (write_flag == -1)
        {
            perror("error");
            _exit(1);
        }
    }
    printf("copied...........\n");
    close(sfid);
    close(dfid);

    return 0;
}

/*
ainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_7$ cc 7.c
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_7$ ./a.out
copied...........
*/