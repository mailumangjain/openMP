#include<stdio.h>
#include<time.h>

void main()
{
	unsigned int count=90000,sum=0,i;clock_t begin,end;
	begin = clock();
	for (i = 0 ; i<=count;i++)
	{
		sum = sum +i ;
	}
	end = clock();
	double time = ((double)end-begin)/CLOCKS_PER_SEC ;
	printf("The sum is : %d\n",sum);
	printf("The time taken is : %lf\n",time);


}