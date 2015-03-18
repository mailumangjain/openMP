#include<stdio.h>

void main()
{	int i ;
	double sum = 0,x;
	int count = 10000;
	double step = 1/(double)count;
	for (i=0 ; i<= count;i++)
	{
		x= (i+.5)*step;
		sum = sum + 4/(1+ x*x)*step; 
	}
	printf("THe integral is %lf\n", sum);
	 





}
