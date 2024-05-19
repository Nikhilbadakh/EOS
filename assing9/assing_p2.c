#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// p2 -- reader
int main() {
	int fd, cnt1,cnt2,num1,num2,res,cnt3;
	fd = open("/tmp/desd_fifo", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("waiting for num1 and num2:\n");
	cnt1 = read(fd, &num1, sizeof(num1));
	cnt2=  read(fd, &num2, sizeof(num2));

	printf("read from fifo: %d bytes\n", cnt1);

	close(fd);

	fd=open("/tmp/desd_fifo1",O_WRONLY);
	if(fd<0){
	perror("open() failed");
	_exit(1);
	}

	res=num1+num2;
	cnt3=write(fd,&res,sizeof(res));
	close(fd);

	return 0;
}


