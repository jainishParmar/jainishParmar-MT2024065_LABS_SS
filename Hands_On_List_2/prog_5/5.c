//jainish parmar
//MT2024065
/*
Write a program to print the system limitation of        
 a. maximum length of the arguments to the exec family of functions.         
 b. maximum number of simultaneous process per user id.         
 c. number of clock ticks (jiffy) per second.        
 d. maximum number of open files        
 e. size of a page        
 f. total number of pages in the physical memory        
 g. number of currently available pages in the physical memory.
*/

#include <unistd.h> 
#include <stdio.h>  

void print(char *text, long value, char *unit)
{
    printf("%s - %ld %s\n", text, value, unit);
}

void main()
{
    long value;

    value = sysconf(_SC_ARG_MAX);
    if(value == -1)
        perror("Error while getting _SC_ARG_MAX!");
    else 
        print("Maximum length of the arguments to the exec family of functions", value, "");

    value = sysconf(_SC_CHILD_MAX);
    if(value == -1)
        perror("Error while getting _SC_CHILD_MAX!");
    else 
        print("Maximum number of simultaneous process per user id", value, "");

    value = sysconf(_SC_CLK_TCK);
    if(value == -1)
        perror("Error while getting _SC_CLK_TCK!");
    else 
        print("Number of clock ticks (jiffy) per second", value, "");
        
    value = sysconf(_SC_OPEN_MAX);
    if(value == -1)
        perror("Error while getting _SC_OPEN_MAX!");
    else 
        print("Maximum number of open files", value, "");

    value = sysconf(_SC_PAGESIZE);
    if(value == -1)
        perror("Error while getting _SC_PAGESIZE!");
    else 
        print("Size of a page", value, "bytes");

    value = sysconf(_SC_PHYS_PAGES);
    if(value == -1)
        perror("Error while getting _SC_PHYS_PAGES!");
    else 
        print("Total number of pages in the physical memory", value, "");

    value = sysconf(_SC_AVPHYS_PAGES);
    if(value == -1)
        perror("Error while getting _SC_AVPHYS_PAGES!");
    else 
        print("Number of  currently available pages in the physical memory", value, "");

}