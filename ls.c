// program for simulation of ls UNIX command
// ls

#include <stdio.h>  // for perror system call and printf
#include <dirent.h> // for opendir system call

void main(int argc, char *argv[]){
    DIR *dp;
    struct dirent *dirp;
    dp = opendir(argv[1]);
    printf("Files in directory %s are:\n", argv[1]);
    while((dirp = readdir(dp)) != 0){
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
}
