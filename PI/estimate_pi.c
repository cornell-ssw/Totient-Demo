#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define SEED 35791246

int main(int argc, char **argv) {
    // number of iterations requested (no error checking)
    int niter = atoi(argv[1]);

    // seed the RNG
    srand(SEED);

    int count = 0;
    for(int i = 0; i < niter; ++i) {
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;
        double z = x*x + y*y;
        if (z<=1) ++count;
    }

    // the resultant estimate of pi
    double pi = (double) count / niter*4;
    printf("num trials=%d, estimate of pi=%g\n", niter, pi);
}
