#include <assert.h>
#include <stdio.h>
#define ASSERT(condition,...) assert(\
    condition||!(fprintf(stderr,__VA_ARGS__)&&fprintf(stderr,"\n"))\
);
