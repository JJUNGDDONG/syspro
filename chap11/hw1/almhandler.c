#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void (*signal(int signo, void (*handler)(int)))(int) {
    struct sigaction act, old_act;


    act.sa_handler = handler;
    sigemptyset(&act.sa_mask); 
    act.sa_flags = 0;        

    
    if (sigaction(signo, &act, &old_act) < 0) {
        return SIG_ERR; 
    }

   
    return old_act.sa_handler;
}


void alarmHandler(int signo) {
    printf("Wake up\n");
    exit(0);
}

int main() {
 
    signal(SIGALRM, alarmHandler);
    alarm(5);

    short i = 0;
    while (1) {
        sleep(1); 
        i++;
        printf("%d second\n", i);
    }

    printf("end\n");
    return 0;
}

