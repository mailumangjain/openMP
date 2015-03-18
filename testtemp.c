#include<stdio.h>
#include<omp.h>

void main()
{	int i ;
	double sum = 0,y;
	int count = 10000;
	double step = 1/(double)count;
	double t1 = omp_get_wtime();
	for (i=0 ; i<= count;i++)
	{
		y = 4*(1/(1+(i*step)*(i*step)));
		sum = sum + y*step; 
	}
	double t2 = omp_get_wtime();
	printf("THe integral is %lf\n", sum);
	 printf("Time taken : %lf\n",t2-t1 );





}
