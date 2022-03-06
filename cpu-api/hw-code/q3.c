#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    
    pid_t pid = fork();

    if (pid < 0){
        fprintf(stderr, "FORK FAILED\n");
        exit(1);
    } 
    else if (pid == 0) {

        printf("hello\n");
    }
    else{
        printf("goodbye\n");
        

    }

}

