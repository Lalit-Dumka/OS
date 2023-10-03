// program for simulation of grep UNIX command
// grep pattern filename

#include <stdlib.h> // for exit system call
#include <stdio.h>  // for perror system call and printf
#include <string.h> // for strcmp
#define MAX 1024
void usage(){
    printf("Usage: \t ./a.out filename word \n");
}
int main(int argc, char *argv[]){
    FILE *fp;
    char fline[MAX];
    char *newline;
    int count = 0; // line number in file
    int occurrence = 0; // number of times word occurs in file
    if(argc != 3){
        usage();
        exit(1);
    }
    if(!(fp = fopen(argv[1], "r"))){
        printf("grep: Error in opening file: %s \n", argv[1]);
        exit(1);
    }
    while(fgets(fline, MAX, fp)!=NULL){
        count++;
        if((newline = strchr(fline, '\n')) != NULL){
            *newline = '\0';
        }
        if(strstr(fline, argv[2]) != NULL){
            printf("%s:%d:%s\n", argv[1], count, fline); // print filename, line number and line content
            occurrence++; // increment occurrence
        }
    }
    printf("Number of occurrences of word %s in file %s are %d\n", argv[2], argv[1], occurrence);
}