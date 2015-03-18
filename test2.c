#include<stdio.h>
#include<omp.h>

int count = 10000;
void main()

{	
	
	int i , nthread;
	double y,value = 0;
	
	double step = 1/(double)count;
	double sum[4]= {0.0,0.0,0.0,0.0};
	omp_set_num_threads(4); //I would like 4 threads please.
	double t1 =  omp_get_wtime() ;
	#pragma omp parallel 	// 'Each' thread will run the pragma code block
	
	{	int id,nthrd; 
		id= omp_get_thread_num();
		printf("My id is : %d\n",id);
		nthrd = omp_get_num_threads(); // returns number of threads in a team
		
		#pragma omp critical
		for (i=0 ; i<=count;i=i+nthrd)
	{	
		y = 4*(1/(1+(i*step)*(i*step)));
		sum[id] = sum[id] + y*step; 
	}

	}
	double t2 =  omp_get_wtime();	
	
		for (i=0 ; i<4;i++)
		{	

			value = value + sum[i];

		}	

printf("THe integral is %lf\n", value);
printf("The time taken : %lf\n", t2-t1);
}	 






