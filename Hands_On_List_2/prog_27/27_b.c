//jainish parmar
//MT2024065
// Question : Write a program to receive messages from the message queue with `IPC_NOWAIT` as a flag

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>  
#include <stdio.h>     
#include <unistd.h>   

void main()
{
    key_t queueKey;     
    int queueIdentifier; 
    ssize_t messageSize; 

    struct msgbuf
    {
        long mtype;      
        int  someNumber; 
    } data;

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);

    if (queueIdentifier == -1)
    {
        perror("Error while creating message queue!");
        _exit(0);
    }

    data.mtype = 1;

    messageSize = msgrcv(queueIdentifier, &data, sizeof(data), data.mtype, IPC_NOWAIT);

    if(messageSize == -1) {
        perror("Error while sending getting via Message Queue!");
        _exit(0);
    }

    printf("Received number: %d\n", data.someNumber);
}