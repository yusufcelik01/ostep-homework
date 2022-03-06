#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(){
    
    pid_t pid = fork();

    if (pid < 0){
        fprintf(stderr, "FORK FAILED\n");
        exit(1);
    } 
    else if (pid == 0) {
        printf("HELLO from child\n");


        printf("Child is writing id is %d\n", pid);
    }
    else{
        printf("HELLO from parent\n");
        pid_t cid = waitpid(pid, NULL, 0);
        printf("Parents writing, its childs id is %d, wait returns %d\n", pid, cid);
        

    }

}
