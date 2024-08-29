//jainish parmar
//MT2024065
//Write a program to execute ls -Rl by the following system calls 
//    d. execv 


#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[],char *env[]){

    char *command_path = "/bin/ls";
    char *options = "-Rl";
    char *arr[] = {command_path,options,NULL}; 
    execv(arr[0], arr);
    return 0;
}

/*
.:
total 32
-rw-rw-r-- 1 jainish-parmar jainish-parmar  2862 Aug 29 12:42 27_a.c
-rw-rw-r-- 1 jainish-parmar jainish-parmar   658 Aug 29 12:50 27_b.c
-rw-rw-r-- 1 jainish-parmar jainish-parmar  3040 Aug 29 12:53 27_c.c
-rw-rw-r-- 1 jainish-parmar jainish-parmar   347 Aug 29 12:57 27_d.c
-rwxrwxr-x 1 jainish-parmar jainish-parmar 16000 Aug 29 12:57 a.out
 */