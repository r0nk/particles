#include "vector.h"

struct vector cross (struct vector u, struct vector v)
{
	struct vector vec;
	vec.x = (u.y*v.z) - (u.z*v.y);
	vec.y = (u.z*v.x) - (u.x*v.z);
	vec.z = (u.x*v.y) - (u.y*v.x);
	return vec;
}

int dot(struct vector v1, struct vector v2)
{
	int ret=0;
	ret+=(v1.x*v2.x);
	ret+=(v1.y*v2.y);
	ret+=(v1.z*v2.z);
	return ret;
}

struct vector add(struct vector v1, struct vector v2)
{
	struct vector v;
	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return v;
}

struct vector v_scalar_mul(int a,struct vector v1)
{
	struct vector v;
	v.x = v1.x * a;
	v.y = v1.y * a;
	v.z = v1.z * a;
	return v;
}
