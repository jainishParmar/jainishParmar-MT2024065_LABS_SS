//jainish parmar
//MT2024065
//Create the following types of a files using (i) shell command (ii) system call 
//1. hardlink


//command line  ln a.txt b.txt

#include<stdio.h>
#include<unistd.h>


int main(int argc,char* argr[]){

    if(argc<2){
        perror("insuffienet argument");
        return 0;
    }

    char* ori_path=argr[1];
    char* dupli_path=argr[2];


    int st;
    st=link(ori_path,dupli_path);
    if(st==-1){
        perror("Error while creating hard link!");
    }
    printf("succesfully created hard link");
    char *command_path = "/bin/ls";
    char *options = "-Rl";
    // char *file_arg = "../../Hands_on_List_1"; 
    execl(command_path, command_path, options, NULL);
    return 0;


}

/*

jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_1$ ./a.out ./a.txt ./b.txt
.:
total 28
-rw-rw-r-- 1 jainish-parmar jainish-parmar   722 Aug 29 15:18 1_a.c
-rwxrwxr-x 1 jainish-parmar jainish-parmar 16080 Aug 29 15:22 a.out
-rw-rw-r-- 2 jainish-parmar jainish-parmar    16 Aug 29 15:11 a.txt
-rw-rw-r-- 2 jainish-parmar jainish-parmar    16 Aug 29 15:11 b.txt
 */
