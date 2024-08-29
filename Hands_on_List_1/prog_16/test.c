#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int fd=open("a.txt",O_RDONLY);
    if(fd==-1){
        perror("error");
        _exit(1);
    }
    printf("file opened for read\n");
    return 0;
}