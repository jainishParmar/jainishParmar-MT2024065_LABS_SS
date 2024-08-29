// jainish parmar
// MT2024065
// 30 Write a program to run a script at a specific time using a Daemon process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{

     if (argc < 2){
        printf("Pass at least one argument\n");
        return 0;
    }
    time_t curr, dead;
    struct tm *deadline;
    time(&curr);
    deadline = localtime(&curr);

    deadline->tm_hour = atoi(argv[1]);
    deadline->tm_min = argv[2] == NULL ? 0 : atoi(argv[2]);
    deadline->tm_sec = argv[3] == NULL ? 0 : atoi(argv[3]);

    dead = mktime(deadline);

    int cid = fork();
    if (cid == 0)
    {
        setsid();
        do
        {
            time(&curr);
        } while (difftime(dead, curr) > 0);
        system("echo Current user=$USER");
    }
    else
    {
        exit(0);
    }

    return 0;
}

/*
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1$ cd prog_30
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_30$ ./a.out 14 33 00
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_30$ Current user=jainish-parmar
*/