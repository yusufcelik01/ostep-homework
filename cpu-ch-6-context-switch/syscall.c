#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define BUFF_SIZE 2048
int main() {
    char buff[BUFF_SIZE];
    
    int i;

    struct timeval begin, end;
    for(i = 0; i < BUFF_SIZE; i++) {
        buff[i] = 'a';
    }

    gettimeofday(&begin, NULL);
    for(i = 0; i < BUFF_SIZE; i++) {
        write(STDERR_FILENO, buff, 1);
    }
    //for(i = 0; i < BUFF_SIZE; i++) {
    //    write(STDIN_FILENO, buff, 0);
    //}
    gettimeofday(&end, NULL);

    printf("Begin time: secs: %ld, usecs: %ld\n", begin.tv_sec, begin.tv_usec);
    printf("End time: secs: %ld, usecs: %ld\n", end.tv_sec, end.tv_usec);

    long sec_diff = end.tv_sec - begin.tv_sec;
    long usec_diff = sec_diff*1000000 + end.tv_usec - begin.tv_usec;

    printf("Difference: secs: %ld, usecs: %ld\n", sec_diff, usec_diff);
    printf("average time for a syscall in microsecs: %f\n", (double) usec_diff/BUFF_SIZE);
    



    
    

    


    return 0;
}
