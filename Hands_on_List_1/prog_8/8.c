// jainish parmar
// MT2024065
// 8.Write a program to open a file in read only mode, read line by line and display each line as it is read. 
//Close the file when end of file is reached

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

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
    char line[1024],ch;
    int read_flag;
    int write_flag;
    int i=0;
    while (read(sfid,&line[i],1))
    {
       if(line[i]=='\n'){
        printf("%s",line);
        memset(line,0,sizeof(line));
        i=0;
       }else{
        i++;
       }
    }
    printf("copied...........\n");
    close(sfid);
    close(dfid);

    return 0;
}

/*
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_8$ cc 8.c
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_8$ ./a.out
hello 
this 
side
is
jainish
parmar
copied...........
*/