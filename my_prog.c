#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler1(int sig_num){
    printf("\n Inside first handler\n");
    my_func(sig_num);
}

void handler2(int sig_num){
    printf("\n Inside second handler\n");
    my_func(sig_num);
}

void handler3(int sig_num){
    printf("\n Inside third handler\n");
    my_func(sig_num);
}

void handler4(int sig_num){
    printf("\n Inside fourth handler\n");
    my_func(sig_num);
}

void handler5(int sig_num){
    printf("\n Inside fifth handler\n");
    my_func(sig_num);
}

void my_func(int S){
    if(S == handler1){
        signal(SIGQUIT,handler2);
        signal(SIGUSR1, handler3);
        signal(SIGTSTP, handler4);
        signal(SIGHUP, handler5);
    }
    else if(S == handler2){
        signal(SIGQUIT,handler1);
        signal(SIGUSR1, handler3);
        signal(SIGTSTP, handler4);
        signal(SIGHUP, handler5);
    }
    else if(S == handler3){
        signal(SIGQUIT,handler2);
        signal(SIGUSR1, handler1);
        signal(SIGTSTP, handler4);
        signal(SIGHUP, handler5);
    }
    else if(S == handler4){
        signal(SIGQUIT,handler2);
        signal(SIGUSR1, handler3);
        signal(SIGTSTP, handler1);
        signal(SIGHUP, handler5);
    }
    else{
        signal(SIGQUIT,handler2);
        signal(SIGUSR1, handler3);
        signal(SIGTSTP, handler4);
        signal(SIGHUP, handler1);
    }
}

int main(){
    printf("Inside main function\n");
    int i = 0;
    while(1){
        signal(SIGINT, handler1);
        sleep(1);
        i++;
        printf("%d : Wasting time..\n", i);
    }
    return 0;
}