// PROGRAM FOR SYSTEM CALLS OF UNIX OPERATING SYSTEM (fork, getpid, exit)

#include <stdio.h>  // for perror system call and printf
#include <unistd.h> // for fork system call

int main(){
    int pid, pid1, pid2;
    pid = fork();
    if(pid == -1){
        perror("Error in process creation");
        exit(1);
    }
    if(pid != 0){
        pid1 = getpid();
        printf("Parent process id is %d\n", pid1);
    }
    else{
        pid2 = getpid();
        printf("Child process id is %d\n", pid2);
    }
}