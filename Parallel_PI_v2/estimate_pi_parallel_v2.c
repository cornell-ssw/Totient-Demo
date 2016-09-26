#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <omp.h>

#define SEED 35791246

int main(int argc, char **argv) {
    // number of iterations requested (no error checking)
    int niter = atoi(argv[1]);

    // number of threads to use (no error checking)
    int num_threads = atoi(argv[2]);

    // initialize the storage based on the number of threads
    omp_set_num_threads(num_threads);
    int *thread_sums = (int *)calloc(num_threads, sizeof(int));

    // seed the RNG
    srand(SEED);

    // used to verify we are using the number of threads
    int num_threads_used = -1;

    #pragma omp parallel
    {
        int threadidx = omp_get_thread_num();
        #pragma omp for
        for(int i = 0 ; i < niter; ++i) {
            double x = (double) rand() / RAND_MAX;
            double y = (double) rand() / RAND_MAX;
            double z = x*x + y*y;
            if(z <= 1.0) ++thread_sums[threadidx];
        }

        // verify we used the number of threads we asked for...must be in parallel section
        #pragma omp single
        {
            num_threads_used = omp_get_num_threads();
        }
    }

    // final pass to calculate the overall sum
    int sum = 0;
    for(int i = 0; i < num_threads; i++){
        sum += thread_sums[i];
    }

    // the resultant estimate of pi
    double pi = (double) sum / niter*4;
    printf("num threads=%d, num trials=%d, estimate of pi=%g\n", num_threads_used, niter, pi);
	
    // cleanup and exit
    free(thread_sums);
    return 0;
}
