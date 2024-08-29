//jainish parmar
//MT2024065
//26. Write a program to execute an executable program.    
//a. use some executable program    
//b. pass some input to an executable program. (for example execute an executable of $./a.out name)   
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

    char * args[]={"./temp","hello",NULL};
    execl(args[0],args);
    return 0;
}