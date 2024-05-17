/*The child process send two numbers to the parent process via pipe.
The parent process calculate the sum and return via another pipe. The child process
print the result and exit. The parent process wait for completion of the child and then exit*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
int num1,num2,res,n1,n2,s,r;

int arr1[10],arr2[10],ret,ret1,ret2;

ret = pipe(arr1);
ret1 = pipe(arr2);

ret2 = fork();
if(ret2 == 0){
//child
close(arr1[0]);
close(arr2[1]);
printf("enter two int no. for addition:");
scanf("%d %d",&num1,&num2);

write(arr1[1],&num1,sizeof(num1));
write(arr1[1],&num2,sizeof(num2));

read(arr2[0], &res,sizeof(res));
printf("result: %d\n",res);

close(arr2[0]);
close(arr1[1]);
}

else{
//parent
close(arr1[1]);
close(arr2[0]);
read(arr1[0],&n1,sizeof(n1));
read(arr1[0],&n2,sizeof(n2));

r = n1+n2;

write(arr2[1],&r, sizeof(r));

close(arr2[1]);
close(arr1[0]);
waitpid(-1, &s,0);
}
return 0;
}

















