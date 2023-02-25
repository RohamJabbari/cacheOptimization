# cacheOptimization
This code is written in C. 

Four different implementations of matrix transposition function. (located in implementation.h)


Naive approach: normal implementation.

Cache aware: We are aware of our system's cache size and we utilize it.

Cache oblivious: We do not know the cache size. However, by using a different algorithm (such as Z-curve) we can get the most of cache optimization

Optimized: A combination of a more powerful traversing algorithm (Z-curve) while taking advantage of system's cache size.

To compile and run the code do:

make CC=/opt/global/gcc-11.2.0/bin/gcc

OMP_NUM_THREADS=16 srun --nodes=1 ./llcs-parallel-<version>
  
(change OMP_NUM_THREADS for different thread count)
