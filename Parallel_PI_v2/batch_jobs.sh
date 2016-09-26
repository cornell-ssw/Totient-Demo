#!/usr/bin/env bash

# This script will launch **6** jobs.  You now have the power
# to automate your job submissions, please be conscious of the
# resources you will use doing this.
for threads in {1,2,4,8,16,24}; do
    # Notice that we correspondingly script the number of processors
    # per node that we would like to use.
    qsub -l "nodes=1:ppn=$threads" -v NUM_THREADS="$threads" job-pi-parallel-v2.pbs
done
