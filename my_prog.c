#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <string.h>
#include <assert.h>

/**
 * handler1: SIG
 *
 */

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

void handler6(int sig_num){
    printf("\n Inside 6'th handler");
    struct winsize winsz;
    ioctl(0, TIOCGWINSZ, &winsz);
    printf("SIGWINCH raised, window size: %d rows / %d columns\n",
           winsz.ws_row, winsz.ws_col);
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
    else if (S== handler5){
        signal(SIGQUIT,handler2);
        signal(SIGUSR1, handler3);
        signal(SIGTSTP, handler4);
        signal(SIGHUP, handler1);
    }

    else if (S == handler6){
        signal(SIGWINCH, handler6);
        
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