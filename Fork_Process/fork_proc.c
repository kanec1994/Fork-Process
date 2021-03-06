#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void fork_prac(){
	pid_t pid = fork();
	if(pid == -1){
		printf("Fork process failed");
		exit(1);
	}
	else if(pid == 0){
		printf("PID of the child process is %d and PPID of child process is %d\n", getpid(), getppid());
		char *argv[2];
		argv[0] = "ls";
		argv[1] = NULL;
		execvp("ls", argv); 
		printf("Execvp call failed");
		exit(2);
	}
	else{
		int status;		
		wait(&status);
		printf("PID of the parent process is %d\n", getpid());
		exit(0);
	}
}

int main(){
	fork_prac();
	return(0);
}
