//jainish parmar
//MT2024065
//3. Write a program to set (any one) system resource limit. Use setrlimit system call. 

#include <sys/time.h>     
#include <sys/resource.h> 
#include <stdio.h>        

void print(char *text, rlim_t soft, rlim_t hard, char *unit)
{
    printf("%s - \n", text);

    printf("\tSoft Limit: ");
    if (soft == RLIM_INFINITY)
        printf("Infinite\n");
    else
        printf("%ld %s\n", soft, unit);

    printf("\tHard Limit: ");
    if (hard == RLIM_INFINITY)
        printf("Infinite\n");
    else
        printf("%ld %s\n", hard, unit);

    printf("====================\n");
}

void main()
{
                
    struct rlimit resourceLimits; 

    getrlimit(RLIMIT_CORE, &resourceLimits);
    print("Max size of a core file", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

   
    resourceLimits.rlim_cur = 4096; 
    setrlimit(RLIMIT_CORE, &resourceLimits);
    
   
   getrlimit(RLIMIT_CORE, &resourceLimits);
   print("Max size of a core file", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
    
}