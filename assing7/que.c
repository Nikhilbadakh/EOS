#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/wait.h>

#define MQ_KEY		0x1234

typedef struct numbers {
	long type;
	int num1;
	int num2;
}num_t;

typedef struct result {
	long type;
	int res;
}res_t;

int main() {
	int mqid, ret, s;
	// create message queue
	mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
	if(mqid < 0) {
		perror("msgget() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0) {
		// child: initialize and send the message
		num_t m1;
		m1.type = 1;
		printf("sender: sends two numbers:\n ");
		scanf("%d %d",&m1.num1,&m1.num2 );
		ret = msgsnd(mqid, &m1, sizeof(m1)-sizeof(long), 0);
		printf("sender: message sent: %d\n", ret);

		
		res_t r2;
		printf("child receiving end\n");
		ret=msgrcv(mqid,&r2,sizeof(r2)-sizeof(long),2,0);
		printf("sender reived msg: %d" , r2.res);

	}
	else {
		// parent: receive the message and print it
		num_t m2;
		printf("receiver: waiting for the message...\n");
		ret = msgrcv(mqid, &m2, sizeof(m2)-sizeof(long), 1, 0);
		//printf("receiver: message received: %d -- %d\n", ret, m2.data);

		res_t r1;
		r1.res=m2.num1+m2.num2;

		r1.type=2;
		ret=msgsnd(mqid,&r1,sizeof(r1)-sizeof(long),0);
		printf("parent msg send\n");
		// wait for child and clean it up
		wait(&s);

		// destroy the message queue
		msgctl(mqid, IPC_RMID, NULL);
	}
	return 0;
}








