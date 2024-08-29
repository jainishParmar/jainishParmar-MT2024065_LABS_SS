//jainish parmar
//MT2024065
//Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to 
//verify whether the data is available within 10 seconds or not (check in $man 2 select)


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/time.h>

int main(){

    fd_set readFDSet, writeFDSet;

    struct timeval time;

    int returnVal;

    FD_SET(STDIN_FILENO, &readFDSet);   
    FD_SET(STDOUT_FILENO, &writeFDSet); 

  
    time.tv_sec = 10;
    time.tv_usec = 0;
    returnVal = select(1, &readFDSet, &writeFDSet, NULL, &time);
    if (returnVal == -1)
        perror("ERROR ");
    else if (returnVal) 
        printf("The data is now available\n");
    else 
        printf("No data was given for 10 seconds\n");
    return 0;
}

/*

ainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_13$ ./a.out
jaiNo data was given for 10 seconds
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_13$ ./a.out
jai
The data is now available
*/