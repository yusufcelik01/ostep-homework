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

        pid_t cid = wait(NULL);

        printf("Child is writing id is %d, its childs id is %d\n", pid, cid);
        if(cid == -1) {
            printf("error status of child %d   ECHILD=%d\n", errno, errno==ECHILD);
        }
    }
    else{
        printf("HELLO from parent\n");
        pid_t cid = wait(NULL);
        printf("Parents id is %d, its childs id is %d\n", pid, cid);
        

    }

}
