#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(){
    
    int pipefd[2];

    if(pipe(pipefd) == -1) {
       fprintf(stderr, "PIPE error\n"); 
       exit(1);
    }

    pid_t pid = fork();

    if (pid < 0){
        fprintf(stderr, "FORK FAILED\n");
        exit(1);
    } 
    else if (pid == 0) {
        printf("HELLO from child 1\n");

        dup2(pipefd[0], STDIN_FILENO);

        //printf("Child 1 is writing id is %d\n", 4816);
        int c;
        while((c = getchar()) != '\n' ){
            printf("child 1 has read:%c\n", c);
        }
        //fprintf(stderr, "NO ERROR OCCURED\n");
    }
    else{
        printf("HELLO from parent\n");

        pid_t pid2 = fork();

        if (pid2 < 0) {
            fprintf(stderr, "FORK FAILED\n");
            exit(1);
        }
        else if (pid2 == 0) {
            printf("Hello from child 2\n");
            int var = 4816;

            dup2(pipefd[1], STDOUT_FILENO);

            printf("Child 2 is writing %d\n", var);
        }
        else{
            pid_t cid = waitpid(pid, NULL, 0);
            printf("Parents writing, its childs id is %d, wait returns %d\n", pid, cid);

        }
    }

}

