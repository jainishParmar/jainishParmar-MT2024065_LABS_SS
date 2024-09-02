//jainish parmar
//MT2024065
// 3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
    int fd=creat("b.txt",0777);
    if(fd==-1){
        perror("error");
        return 0;
    }
    printf("\n %d : \n",fd);
    return 0;
}

/*
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_3$ ./a.out

 3 : 
*/