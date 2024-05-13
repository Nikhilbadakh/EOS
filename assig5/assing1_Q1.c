#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret1,ret2,ret3,ret4,ret5,i,s,child_pid;

	ret1 =fork();
	if(ret1 == 0)
	{
		for (i=0; i<=10;i++)
		{
			printf("child:1\n");

			sleep(1);
		}
			_exit(0);
	}

	ret2=fork();
	if(ret2 == 0)
	{
		for (i=0;i<=10;i++)
		{
			printf("child : 2\n");
			sleep(1);
		}
			_exit(0);
	}
	ret3 = fork();
	if(ret3 ==0 )
	{
		for(i=0;i<=10;i++)
		{
			printf("child : 3\n");
			sleep(1);
		}
			_exit(0);
	}
	ret4 = fork();
	if(ret4==0)
	{
		for(i=0;i<=10;i++)
		{
			printf("child : 4\n");
			sleep(1);
		}
			_exit(0);
	}
	ret5= fork();
	if(ret5==0)
	{
		for(i=0;i<=10;i++)
		{
			printf("child :5 \n");
			sleep(1);
		}
			_exit(0);
	}
	else{
		for(i=0;i<10;i++)
		{
			printf("parent\n");
			sleep(1);

		}
	}

	for(i=1;i<=5;i++)
		child_pid= wait(&s);

	return 0;
}
