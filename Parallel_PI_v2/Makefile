# The enviroment variable CC is often defined by users who need a specific
# C compiler or version of a C compiler.  ?= in make says "assign a value
# if one is not already assigned".
#
# So if instead of just executing `make`, the following is entered:
#
#     make CC=icc
#
# then the Intel C Compiler (icc) located in /usr/local/intel/bin
# on Totient will be used instead.
#
# On the totient cluster, add the line
# 
#     module load cs5220
#
# to have `icc` loaded for you in your ~/.bash_profile.
CC ?= gcc
CFLAGS = -O3 -std=c99

# The openmp flag for gcc is different than icc
ifneq (,findstring(gcc,$(CC)))
	CFLAGS += -fopenmp
else
    # assuming compiler is icc, this is not a guarantee though
	# add some optimization flags while we are at it
	CFLAGS += -openmp -no-prec-div -xcore-avx2
endif

.PHONY: all clean

all: pi

pi: estimate_pi_parallel_v2.c
	$(CC) $(CFLAGS) -o estimate_pi_parallel_v2 estimate_pi_parallel_v2.c

clean:
	rm -f estimate_pi_parallel_v2 pi-parallel-v2.o*
