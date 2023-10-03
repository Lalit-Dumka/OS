// PROGRAM FOR SYSTEM CALLS OF UNIX OPERATING SYSTEMS (OPENDIR, READDIR, CLOSEDIR) IN C

#include <stdio.h>  // for perror system call and printf
#include <dirent.h> // for opendir system call
struct dirent *dptr;

int main(int argc, char *argv[]){
    char buff[100]
    DIR *dp;
    printf("Enter directory name: ");
    scanf("%s", buff);
    if((dp = opendir(buff)) == NULL){
        perror("Error in opening directory");
        return 0;
    }
    while((dptr = readdir(dp)) != NULL){
        printf("%s\n", dptr->d_name);
    }
    closedir(dp);
}
