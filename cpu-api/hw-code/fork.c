#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int var = 100;
    
    pid_t pid = fork();

    if (pid < 0){
        fprintf(stderr, "FORK FAILED\n");
        exit(1);
    } 
    else if (pid == 0) {
        //var = 481516;

        printf("This is private child, value of var is %d\n", var);
    }
    else{
        var = -400;
        printf("This is colonel parent, value of var is %d\n", var);
        

    }

}
