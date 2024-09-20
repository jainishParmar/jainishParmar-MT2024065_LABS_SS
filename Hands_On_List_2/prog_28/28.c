// Question : Write a program to change the exiting message queue permission. (Use `msqid_ds` structure)

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>  
#include <stdio.h>     
#include <unistd.h>   

void main()
{
    key_t queueKey;                   
    int queueIdentifier;              
    struct msqid_ds messageQueueInfo; 
    int msgctlStatus;                 

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);
    if (queueIdentifier == -1)
    {
        perror("Error while creating Message Queue!");
        _exit(0);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n\n", queueIdentifier);

    msgctlStatus = msgctl(queueIdentifier, IPC_STAT, &messageQueueInfo);

    if (msgctlStatus == -1)
    {
        perror("Error while getting Message Queue info!");
        _exit(0);
    }

    printf("Press enter to change the permissions!\n");
    getchar();

    messageQueueInfo.msg_perm.mode = 0777;

    msgctlStatus = msgctl(queueIdentifier, IPC_SET, &messageQueueInfo);

    if (msgctlStatus == -1)
    {
        perror("Error while changing Message Queue permission!");
        _exit(0);
    }
}