//jainish parmar
//MT2024065
//Write a program to execute ls -Rl by the following system calls 
//a.execl

#include<stdio.h>
#include<unistd.h>
int main(){

    char *command_path = "/bin/ls";
    char *options = "-Rl";
    char *file_arg = "../../Hands_on_List_1"; 
    execl(command_path, command_path, options, file_arg, NULL);
    printf("hello return");
    return 0;
}

/*

../../Hands_on_List_1:
total 36
drwxrwxr-x 2 jainish-parmar jainish-parmar 4096 Aug 23 14:48 prog_19
drwxrwxr-x 2 jainish-parmar jainish-parmar 4096 Aug 23 15:06 prog_20
drwxrwxr-x 2 jainish-parmar jainish-parmar 4096 Aug 23 15:30 prog_21
drwxrwxr-x 2 jainish-parmar jainish-parmar 4096 Aug 23 15:48 prog_22
drwxrwxr-x 2 jainish-parmar jainish-parmar 4096 Aug 29 10:55 prog_23
drwxrwxr-x 2 jainish-parmar jainish-parmar 4096 Aug 29 10:57 prog_24
drwxrwxr-x 2 jainish-parmar jainish-parmar 4096 Aug 29 11:29 prog_25
drwxrwxr-x 2 jainish-parmar jainish-parmar 4096 Aug 29 12:30 prog_26
drwxrwxr-x 2 jainish-parmar jainish-parmar 4096 Aug 29 12:42 prog_27

../../Hands_on_List_1/prog_19:
total 24
-rwxrwxr-x 1 jainish-parmar jainish-parmar 17816 Aug 23 14:48 19
-rw-rw-r-- 1 jainish-parmar jainish-parmar   669 Aug 23 14:48 19.c

../../Hands_on_List_1/prog_20:
total 20
-rw-rw-r-- 1 jainish-parmar jainish-parmar   321 Aug 23 15:18 20.c
-rwxrwxr-x 1 jainish-parmar jainish-parmar 15952 Aug 23 15:06 a.out

../../Hands_on_List_1/prog_21:
total 20
-rw-rw-r-- 1 jainish-parmar jainish-parmar   508 Aug 23 15:33 21.c
-rwxrwxr-x 1 jainish-parmar jainish-parmar 16120 Aug 23 15:30 a.out

../../Hands_on_List_1/prog_22:
total 24
-rw-rw-r-- 1 jainish-parmar jainish-parmar   676 Aug 29 10:45 22.c
-rwxrwxr-x 1 jainish-parmar jainish-parmar 16160 Aug 23 15:48 a.out
-rw-rw-r-- 1 jainish-parmar jainish-parmar    65 Aug 23 15:49 a.txt

../../Hands_on_List_1/prog_23:
total 20
-rw-rw-r-- 1 jainish-parmar jainish-parmar   457 Aug 29 10:57 23.c
-rwxrwxr-x 1 jainish-parmar jainish-parmar 16120 Aug 29 10:55 a.out

../../Hands_on_List_1/prog_24:
total 40
-rwxrwxr-x 1 jainish-parmar jainish-parmar 17736 Aug 29 10:51 24
-rw-rw-r-- 1 jainish-parmar jainish-parmar   448 Aug 29 11:30 24.c
-rwxrwxr-x 1 jainish-parmar jainish-parmar 16120 Aug 29 10:57 a.out

../../Hands_on_List_1/prog_25:
total 20
-rw-rw-r-- 1 jainish-parmar jainish-parmar   542 Aug 29 11:29 25.c
-rwxrwxr-x 1 jainish-parmar jainish-parmar 16032 Aug 29 11:29 a.out

../../Hands_on_List_1/prog_26:
total 40
-rw-rw-r-- 1 jainish-parmar jainish-parmar   382 Aug 29 12:35 26.c
-rwxrwxr-x 1 jainish-parmar jainish-parmar 16000 Aug 29 12:30 a.out
-rwxrwxr-x 1 jainish-parmar jainish-parmar 15952 Aug 29 12:29 temp
-rw-rw-r-- 1 jainish-parmar jainish-parmar   186 Aug 29 12:29 temp.c

../../Hands_on_List_1/prog_27:
total 20
-rw-rw-r-- 1 jainish-parmar jainish-parmar   346 Aug 29 12:41 27.c
-rwxrwxr-x 1 jainish-parmar jainish-parmar 15952 Aug 29 12:42 a.out





*/