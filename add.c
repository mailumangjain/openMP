#include<stdio.h>
#include<omp.h>
// program to add all no. till count;
//multithreaded. threads = 4
//TO  DO : make the program autonomous, take user input count and no. of cores to be used.
void main()
{
	unsigned long count = 90000; int nthreads; unsigned long sum[4]={0,0,0,0}; // change count to see sum till a no.


	omp_set_num_threads(4);
	double t1 =omp_get_wtime();
	#pragma omp parallel
	{ int i,id,nthrd;
			id = omp_get_thread_num(); // get thread id of that particular thread
 			nthrd = omp_get_num_threads();//available no. of threads i.e. <=4(asked)
			printf("ID : %d\n", id  );
			printf("Threads : %d\n",nthrd );
			if(id==0) {nthreads = nthrd; }
			//#pragma omp critical
			for (i=id+1;i<=count-(nthrd-(id+1));i=i+=nthrd) // based on observation
				{sum[id] = sum[id] + i;}

}
	double t2 =omp_get_wtime();
	
	printf("the sum : %ld\n", sum[0]);
	printf("the sum : %ld\n", sum[1]);
	printf("the sum : %ld\n", sum[2]);
	printf("the sum : %ld\n", sum[3]);
	printf("The final sum : %ld\n", sum[0]+sum[1]+sum[2]+sum[3] );
	printf("the number threads : %d\n",nthreads);
	printf("Total time taken : %lf\n",t2-t1);






}