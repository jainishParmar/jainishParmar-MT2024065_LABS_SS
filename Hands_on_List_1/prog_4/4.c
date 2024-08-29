//jainish parmar
//MT2024065
//Write a program to open an existing file with read write mode. Try O_EXCL flag also

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){


    int fd=open("../prog_3/a.txt",O_RDWR);
    if(fd==-1){
        perror("error");
        return 0;
    }else{

	printf("%d \n",fd);
    }
	fd =open("../prog_3/a.txt",O_EXCL);
    if(fd==-1){
        perror("error");
        return 0;
    }else{

	printf("%d \n",fd);
    }
    return 0;
}

/*
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_4$ ./a.out
3 
4 
*/