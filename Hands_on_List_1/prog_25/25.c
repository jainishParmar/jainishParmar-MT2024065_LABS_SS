/*
Jainish Parmar
MT2024065
25) Write a program to create three child processes. The parent should wait for a particular child (use 
waitpid system call). 
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){

    int a,b,c;
    if(!(a=fork())){
        sleep(1);
    }
    else{
        if(!(b=fork())){
            sleep(3);
        }else{
            if(!(c=fork())){
                sleep(10);
            }else{
                waitpid(c,NULL,0);
            }
        }
    }
    return 0;
}