//Input signal number and a process id from user. Send given signal to the given process using 
//kill() syscall.

#include<stdio.h>
#include<signal.h>
#include<unistd.h>


int main() {
int signum , pid ,ret;
printf("Enter the signal no.:");
scanf("%d",& signum);

printf("Enter the process id :");
scanf("%d",& pid);

ret= kill(pid,signum);

printf("%d",ret);
return 0;
}

