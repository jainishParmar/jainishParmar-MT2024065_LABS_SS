//jainish parmar
//MT2024065
//Write a program to execute ls -Rl by the following system calls 
//b. execlp

#include<stdio.h>
#include<unistd.h>

int main(){

    char *path = "ls";
    char* op="-Rl";
    // char *file_arg = "../../Hands_on_List_1"; 

    execlp(path, path, op, NULL);
    return 0;
}

/*

jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_27$ ./a.out
.:
total 24
-rw-rw-r-- 1 jainish-parmar jainish-parmar  2862 Aug 29 12:42 27_a.c
-rw-rw-r-- 1 jainish-parmar jainish-parmar   304 Aug 29 12:49 27_b.c
-rwxrwxr-x 1 jainish-parmar jainish-parmar 15952 Aug 29 12:49 a.out
*/