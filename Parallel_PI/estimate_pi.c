
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SEED 35791246

int main(int argc, char* argv[])
{
	int niter = atoi(argv[1]);
	double x, y;
	int i, sum = 0; /* # of points in the 1st quadrant of unit circle */
	double z;
	double pi;
	/* initialize random numbers */
  	int carray[12];

	#pragma omp parallel
  	{
  		srand(SEED);
  		int num_threads = omp_get_num_threads();
		int threadidx = omp_get_thread_num();
  		int count = 0;
	  	for (i = 0 ; i < niter; i ++ ) {
			x = (double)rand()/RAND_MAX;
			y = (double)rand()/RAND_MAX;
			z = x*x + y*y;
			if (z<=1) count++;
		}

		carray[threadidx] = count;


	}

	for( i = 0; i < 12; i++){
		sum += carray[i];
	}

	pi = (double)sum/niter*4;
	printf("# of trials= %d , estimate of pi is %g \n",niter,pi);
	return 0;

}
