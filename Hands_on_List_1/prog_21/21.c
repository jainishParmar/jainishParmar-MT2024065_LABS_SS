
// jainish parmar
// MT2024065
// use fork() & find process id of child process and parent process.
#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
int main(){
    __pid_t pid=fork();
    if(pid==0){
        printf("child process id %d\n",getpid());
        printf("child's parent process id %d\n",getppid());
    }else{
        printf("parent process id %d\n",getpid());
    }
    wait(0);
    return 0;
}


/*


parent process id 21720
child process id 21721
child's parent process id 21720

*/