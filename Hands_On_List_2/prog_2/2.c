// jainish parmar
// MT2024065
// 2. Write a program to print the system resource limits. Use getrlimit system call.

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
void print(char *text, rlim_t soft, rlim_t hard, char *unit)
{
    printf("%s - \n", text);

    printf("\tSoft Limit: ");
    if (soft == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", soft, unit);

    printf("\tHard Limit: ");
    if (hard == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", hard, unit);
}

void main()
{
    struct rlimit resourceLimits;

    getrlimit(RLIMIT_AS, &resourceLimits);
    print("Max size of process's virtual memory", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    getrlimit(RLIMIT_CORE, &resourceLimits);
    print("Max size of a core file", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    getrlimit(RLIMIT_CPU, &resourceLimits);
    print("Max CPU time that the process can consume", resourceLimits.rlim_cur, resourceLimits.rlim_max, "seconds");

    getrlimit(RLIMIT_RTPRIO, &resourceLimits);
    print("Ceiling on the real-time priority", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");

    getrlimit(RLIMIT_NOFILE, &resourceLimits);
    print("no of open file", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");



}
  