#include<stdio.h>
#include<omp.h>

void main()
{	

	#pragma omp parallel
	{int i = omp_get_thread_num();
	printf("Hello %d\n", i);
	printf("World %d\n", i);
	}
}
