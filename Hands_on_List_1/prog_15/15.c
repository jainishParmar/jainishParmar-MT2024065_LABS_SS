// jainish parmar
// MT2024065
// 15. Write a program to display the environmental variable of the user (use environ).

#include <stdio.h> 

extern char **environ;

int isUser(char *var)
{
    return var[0] == 'U' && var[1] == 'S' && var[4] == '=';
}

int main()
{
    int iter = 0;
    while (environ[++iter] != NULL)
        if (isUser(environ[iter]))
            printf("%s\n", environ[iter]);

    return 0;
}

/*
USER=jainish-parmar
*/
