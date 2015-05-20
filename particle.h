#ifndef ION
#define ION 1
#include "vector.h"

struct particle {
	double mass;
	struct vector l;/* location */
	struct vector velocity;//gets added after every calc
};

#endif
