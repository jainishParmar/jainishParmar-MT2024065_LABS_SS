// jainish parmar
// MT2024065
// Create the following types of a files using (i) shell command (ii) system call
// 3 mkfifo

#include <sys/types.h> 
#include <sys/stat.h>  
#include <stdio.h>     
#include<unistd.h>
#include<sys/wait.h>
int main(){
    char *mkfifoName = "./mymkfifo";    
    int mkfifo_status;
    mkfifo_status = mkfifo(mkfifoName, S_IRWXU);
    if (mkfifo_status == -1){
        perror("Error while creating FIFO file!");
    }
    else{
        printf("Succesfully created FIFO file");
        sleep(5);
        char *command_path = "/bin/ls";
        char *options = "-l";
        // char *file_arg = "../../Hands_on_List_1";
        execl(command_path, command_path, options, NULL);
    }
    return 0;
}

/*
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_1$ ./a.out
total 40
-rw-rw-r-- 1 jainish-parmar jainish-parmar  1159 Aug 29 15:30 1_a.c
-rw-rw-r-- 1 jainish-parmar jainish-parmar  1396 Aug 29 15:31 1_b.c
-rw-rw-r-- 1 jainish-parmar jainish-parmar   732 Aug 29 16:17 1_c.c
-rwxrwxr-x 1 jainish-parmar jainish-parmar 16120 Aug 29 16:17 a.out
-rw-rw-r-- 2 jainish-parmar jainish-parmar    16 Aug 29 15:11 a.txt
-rw-rw-r-- 2 jainish-parmar jainish-parmar    16 Aug 29 15:11 b.txt
-rw-rw-r-- 1 jainish-parmar jainish-parmar    29 Aug 29 15:30 c.txt
lrwxrwxrwx 1 jainish-parmar jainish-parmar     7 Aug 29 15:29 d.txt -> ./c.txt
prwx------ 1 jainish-parmar jainish-parmar     0 Aug 29 16:17 mymkfifo
*/