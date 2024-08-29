//jainish parmar
//MT2024065
//Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include <sys/wait.h>

int main(){
    int n=5;
    int fd=open("a.txt",O_RDWR);
    pid_t pid=fork();
    while(n--){
        if(pid==0){
            //child;
            write(fd,"child\n",strlen("child\n"));
            sleep(1);
        }else{
            //parent;
             write(fd,"parent\n",strlen("parent\n"));
             sleep(2);
        }
    }
    wait(0);
    close(fd);
    return 0;
}

//output in a.txt