//jainish parmar
//MT2024065
//4. Write a program to measure how much time is taken to execute 100 getpid ( ) system call. Use time stamp counter. 


#include <sys/time.h>  
#include <sys/types.h> 
#include <unistd.h>    
#include <stdio.h>    


unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc"
                         : "=A"(dst));
    return dst;
}
void main()
{
    int start, end, pid;
    struct timeval timestamp;
    int iter = 0;
    start = rdtsc();
    while(iter < 100) {
        pid = getpid();
        iter++;
    }
    end = rdtsc();
    printf("PID: %d\n", pid);
    printf("Time taken : %d ns \n",  (int) ((end - start)/2.4));
}