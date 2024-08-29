//jainish parmar
//MT2024065
// Write a simple program to execute in an infinite loop at the background. Go to /proc directory and 
// identify all the process related information in the corresponding proc directory

#include<stdio.h>
int main(){
    while(1){

    }
    return 0;
}

/*

jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_2$ ./a.out &
[1] 22639
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_2$ ^C
jainish-parmar@jainish-parmar-IdeaPad-5-15ITL05:/media/jainish-parmar/part2/software_system/lab/Hands_on_List_1/prog_2$ cat /proc/22639/status
Name:   a.out
Umask:  0002
State:  R (running)
Tgid:   22639
Ngid:   0
Pid:    22639
PPid:   18160
TracerPid:      0
Uid:    1000    1000    1000    1000
Gid:    1000    1000    1000    1000
FDSize: 256
Groups: 4 24 27 30 46 100 114 1000 
NStgid: 22639
NSpid:  22639



*/