 //jainish parmar
 //MT2024065
 //Write a program to create a Zombie state of the running program


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    __pid_t t=fork();
   if(t==0)
   {
       printf("Child having id %d\n",getpid());
       _exit(0);
    }
    else
    {
        printf("Parent having id %d\n",getpid());
        sleep(100); 
    }
}
//zombie state
//process flag change to  "Z";
//Name:	a.out
//State:	Z (zombie)
