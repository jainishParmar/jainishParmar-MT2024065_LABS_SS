//jainish parmar
//MT2024065
//6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls 

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    char *buf;

    read(1,buf,100);
    write(0,buf,sizeof(buf));

    return 0;
}

/*

jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_6$ cc 6.c
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_6$ ./a.out
jainish
jainish
*/