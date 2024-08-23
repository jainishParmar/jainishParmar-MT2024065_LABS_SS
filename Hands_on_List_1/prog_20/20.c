
// jainish parmar
// MT2024065
// find priority of process and modfiy it.
#include<stdio.h>
int main(){
    while(1){
       printf("hello");
    }
    return 0;
}


/*

running program in background
pid:15983

change priority to -10;
renice -10 15983

output : 

15983 (process ID) old priority 0, new priority -10


*/