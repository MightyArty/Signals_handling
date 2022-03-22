#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler1(int sig_num){
    printf("Inside first handler\n");
    my_func(sig_num);
}

void handler2(int sig_num){
    printf("Inside second handler\n");
    my_func(sig_num);
}

void handler3(int sig_num){
    printf("Inside third handler\n");
    my_func(sig_num);
}

void handler4(int sig_num){
    printf("Inside fourth handler\n");
    my_func(sig_num);
}

void handler5(int sig_num){
    printf("Inside fifth handler\n");
    my_func(sig_num);
}

void my_func(int S){
    if(S == handler1){
        signal(SIGQUIT,handler2);
        signal(SIGUSR1, handler3);
        signal(SIGUSR2, handler4);
        signal(SIGHUP, handler5);
    }
    else if(S == handler2){
        signal(SIGQUIT,handler1);
        signal(SIGUSR1, handler3);
        signal(SIGUSR2, handler4);
        signal(SIGHUP, handler5);
    }
    else if(S == handler3){
        signal(SIGQUIT,handler2);
        signal(SIGUSR1, handler1);
        signal(SIGUSR2, handler4);
        signal(SIGHUP, handler5);
    }
    else if(S == handler4){
        signal(SIGQUIT,handler2);
        signal(SIGUSR1, handler3);
        signal(SIGUSR2, handler1);
        signal(SIGHUP, handler5);
    }
    else{
        signal(SIGQUIT,handler2);
        signal(SIGUSR1, handler3);
        signal(SIGUSR2, handler4);
        signal(SIGHUP, handler1);
    }
}

int main(){
    printf("Inside main function\n");
    while(1){
        signal(SIGINT, handler1);
    }
    return 0;
}