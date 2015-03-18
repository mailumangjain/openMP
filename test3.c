#include<stdio.h>
#include<omp.h>
void main()
{
	int a [5] = {1,2,3,4,5};int sum[2]={0,0};int nthreads;
	int b[5] = {6,7,8,9,10};
	omp_set_num_threads(2);
	double t1 = omp_get_wtime();
	#pragma omp parallel
	{
			int i,id; 
			id = omp_get_thread_num();
			int nthrd = omp_get_num_threads();
			if(id==0) nthreads=nthrd ;
			for (i=0;i<=4;i++)
					
					{if (id==0)
						{sum[id]=sum[id] + a[i];}
					if (id==1)
						{sum[id]=sum[id] + b[i];}

					}		



	} 
	
	double t2= omp_get_wtime();
	printf("The sum of a : %d\n",sum[0] );
	printf("The sum of b : %d\n",sum[1] );
	printf("the time : %lf\n",t2-t1);
	printf("The no of thread : %d\n",nthreads );

}