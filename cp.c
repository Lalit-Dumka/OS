// c program for simulation of cp UNIX command
// cp source.txt destination.txt

#include <stdio.h>  // for perror system call and printf 
#include <fcntl.h> // for open system call
#include <unistd.h> // for read and write system call


// wrong implementation
void main(int argc, char *argv[]){
    FILE *fp;
    char ch;
    int sc = 0;
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        perror("Error in opening file");
        return;
    }
    while(!feof(fp)){
        ch = fgetc(fp);
        if(ch == ' ') sc++;
    }
    printf("Number of spaces in file are %d", sc);
    fclose(fp);
}

// correct implementation of cp command
void main(int argc, char *argv[]){
    int fd1, fd2, n;
    char buf[1024];
    if(argc != 3){
        printf("Usage: ./a.out source.txt destination.txt");
        return;
    }
    fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1){
        perror("Error in opening file");
        return;
    }
    fd2 = open(argv[2], O_WRONLY | O_CREAT, 0666);
    if(fd2 == -1){
        perror("Error in opening file");
        return;
    }
    while((n = read(fd1, buf, 1024)) > 0){
        write(fd2, buf, n);
    }
    close(fd1);
    close(fd2);
}
