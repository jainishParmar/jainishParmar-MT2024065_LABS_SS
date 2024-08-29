 //jainish parmar
 //MT2024065
 //Write a program to create a orphan state of the running program

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    __pid_t t=fork();
   if(t==0)
   {
       printf("Child having id %d\n",getpid());
       sleep(10000); 
    }
    else
    {
        printf("Parent having id %d\n",getpid());
       _exit(0);
    }
}

//sleeping state
/*

Name:	a.out
Umask:	0002
State:	S (sleeping)

*/

