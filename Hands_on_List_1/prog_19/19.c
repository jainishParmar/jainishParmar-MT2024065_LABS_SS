// jainish parmar
// MT2024065
// Write a program to find out time taken to execute getpid system call. Use time stamp counter.

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long time_stamp()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc" : "=A"(dst));
    return dst;
}

int main()
{
    int pid = fork();
    if (pid == 0)
    {
        long long int start, end;
        start = time_stamp();
        int ans=getpid();
        end = time_stamp();
        printf("process_id:= %d\n", ans);
        printf("time taken is : %llu\n", end - start);
    }
    return 0;
}

//output : 
// porcess_id:11634
// time taken is:2951