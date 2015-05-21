#include "vector.h"
#include "calculus.h"

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

struct vector v_add(struct vector v1, struct vector v2)
{
	struct vector v;
	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return v;
}

struct vector v_sub(struct vector v1, struct vector v2)
{
	struct vector v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return v;
}

struct vector v_scalar_mul(double a,struct vector v1)
{
	struct vector v;
	v.x = v1.x * a;
	v.y = v1.y * a;
	v.z = v1.z * a;
	return v;
}

struct vector v_scalar_divide(double a,struct vector v1)
{
	struct vector v;
	v.x = v1.x / a;
	v.y = v1.y / a;
	v.z = v1.z / a;
	return v;
}

struct vector v_grad(double (*sf)(struct vector v),struct vector cv)
{
	struct vector v,tv = {0,0,0};
	double L = limit(0);

	v.x = sf(cv);
	v.y = sf(cv);
	v.z = sf(cv);

	cv.x+=L;
	tv.x =sf(cv);
	cv.x-=L;

	cv.y+=L;
	tv.y =sf(cv);
	cv.y-=L;

	cv.z+=L;
	tv.z =sf(cv);
	//cv.z-=L;// we dont need to.

	v = v_sub(tv,v);
	v = v_scalar_divide(L,v);
	return v;
}

double v_div(struct vector (*vf)(struct vector v),struct vector cv)
{
	double ret;

	struct vector v,tv = {0,0,0};
	double L = limit(0);

	v = vf(cv);

	cv.x+=L;
	tv.x =vf(cv).x;
	cv.x-=L;

	cv.y+=L;
	tv.y =vf(cv).y;
	cv.y-=L;

	cv.z+=L;
	tv.z =vf(cv).z;
	//cv.z-=L;// we dont need to.

	v = v_sub(tv,v);
	v = v_scalar_divide(L,v);

	ret = v.x+v.y+v.z;
	return ret;
}

struct vector v_curl(struct vector (*vf)(struct vector v),struct vector cv)
{
	struct vector v,iv;
	/*TODO*/
	return v;
}
