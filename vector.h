#ifndef VECTOR
#define VECTOR

struct vector {
	double x,y,z;
};

struct vector cross (struct vector v1, struct vector v2);
int dot(struct vector v1, struct vector v2);
struct vector add(struct vector v1, struct vector v2);
struct vector v_scalar_mul(int a,struct vector F);

#endif
