#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <dirent.h>


/**
 * @brief This function is just for highliting the text in the terminal
 * 
 */
void red () {
  printf("\033[1;31m");
}
void yellow() {
  printf("\033[1;33m");
}
void blue(){
	printf("\033[0;34m");
}
void green(){
	printf("\033[0;32m");
}
void purple(){
	printf("\033[0;35m");
}
void black(){
	printf("\033[0;30m");
	printf("\033[47m");
}
void cyan(){
	printf("\033[0;36m");
}
void backround(){
	printf("\033[43m");
}
void reset () {
  printf("\033[0m");
}

void sig_handler(int signum)
{
	int i=5;
	int j=0;
	int k = 1;
	switch (signum) 
    {
		case SIGCHLD: // dad is dead
			red();
			printf("I'm the first signal..\n");
			sleep(1);
			raise(SIGUSR1);
		case SIGUSR1: // raise by user signal
			yellow();
			printf("I'm the second signal %d / %d\n",i, j);
			sleep(k);
			k=i/j;
		case SIGFPE: //div by zero exception
			purple();
			printf("I'm the third signal, error in opening file\n");
			black();
			printf("Trying to open we want good grade file\n");
			printf("The list of files located on this device:");
			DIR *d;
  			struct dirent *dir;
			reset();
  			d = opendir(".");
  			if (d) {
				printf("\n[");
    			while ((dir = readdir(d)) != NULL) {
      			printf("%s, ", dir->d_name);
    			}
			  }
			printf("]\n");
    		closedir(d);
			fopen("we want good grade!","r");
		case SIGIO: // file not fount exception
			cyan();
		  	printf("I'm the fourth signal\n");
			printf("Calles abort() function\n");
			abort();
		case SIGABRT: //out of time exception
			green();
		    printf("I'm the fifth signal\n");
		    int a[1] = {0};
			printf("the array is {%d}\n",a[0]);
		    a[2]=1;
		case SIGSEGV:   //out of bounds exception
			blue();
		    printf("I'm the sixth signal\n");
			printf("For switching to the next signal, please resize the terminal window\n");
			pause();
		case SIGWINCH:	// resize of the terminal window
			backround();
			printf("I'm the seventh signal\n");
			struct winsize winsz;

    		ioctl(0, TIOCGWINSZ, &winsz);
    		printf("SIGWINCH raised, window size: %d rows / %d columns",
           		winsz.ws_row, winsz.ws_col);
			reset();
			printf("\n");
		default: 
			exit(1);
			}
}

int main()
{
	int status;
	signal (SIGCHLD, sig_handler);
	signal (SIGUSR1, sig_handler);
	signal (SIGFPE, sig_handler);
    signal (SIGIO, sig_handler);
    signal (SIGABRT, sig_handler);
    signal (SIGSEGV, sig_handler);
	signal (SIGWINCH, sig_handler);

	if (!(fork())) 
        {	
        exit(1);
	}
	wait(&status);

}