/*  Q2) From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). All these
	processes should run concurrently for 5 seconds and cleaned up properly upon termination.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main (void){
	int ret1,ret2,ret3,s1,s2,s3;
	ret1= fork();
	sleep(1);
	if (ret1 == 0) {
		ret2 = fork();
		if(ret2==0){
			ret3 = fork();
			if(ret3 == 0){
				printf("child 3 is child of child2\n");    
				printf("child of %d is %d\n",getppid(),getpid());
				_exit(1);

			}
			printf("child2 is child of child1\n");
			printf("child of %d is %d \n",getppid(),getpid());
			_exit(1);
		}
		printf("child 1 is main child\n");
		printf("child of %d is %d \n",getppid(),getpid());
		_exit(1);
	}
	printf("parent : %d\n",getpid());
	waitpid(ret1,&s3,0);

}
