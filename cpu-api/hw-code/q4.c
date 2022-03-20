#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char** environ;

int main(){
    
    pid_t pid = fork();

    if (pid < 0){
        fprintf(stderr, "FORK FAILED\n");
        exit(1);
    } 
    else if (pid == 0) {
        printf("hello\n");
        
        char* args[4];
        args[0] = "ls";
        args[1] = "-ahl";
        args[2] = "-t";
        args[3] = NULL;

        //execl("/bin/ls", "ls", "-a", "-l", NULL);
        //execlp("/bin/ls", args[0], args[1], args[2], NULL);
        //execle("/bin/ls", args[0], args[1], args[2], NULL, environ);
        //execv("/bin/ls", args);
        execvp("/bin/ls", args);
        printf("THIS SHOULD NOT PRINTF OUT\n");
        //system("ls -al")
        //execvpe("/bin/ls", args, environ);
        
    }
    else{
        printf("goodbye\n");
        

    }

}

