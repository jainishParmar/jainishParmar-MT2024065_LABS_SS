// jainish parmar
// MT2024065
// Write a program to find out time taken to execute getpid system call. Use time stamp counter.

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc()
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

        start = rdtsc();
        printf("process_id:= %d\n", getpid());
        end = rdtsc();

        printf("time taken is : %llu\n", end - start);
    }
    return 0;
}