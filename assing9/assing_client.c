#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// p1 -- writer
int main() {
	int fd, cnt1,cnt2,num1,num2,cnt3,res;
	fd = open("/tmp/desd_fifo", O_WRONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("enter two numbwers:");
	scanf("%d%d", &num1,&num2);

	cnt1 = write(fd, &num1, sizeof(num1));
	cnt2 = write(fd, &num2, sizeof(num2));
	printf("written in fifo: %d %dbytes\n",cnt1,cnt2);

	close(fd);


	fd=open("/tmp/desd_fifo1",O_RDONLY);
	if(fd<0){
	perror("open() failed");
	_exit(1);

	}

	cnt3=read(fd,&res,sizeof(res));

	printf("addition of %d and %d is :%d",num1,num2,res);
	close(fd);
	return 0;
}

