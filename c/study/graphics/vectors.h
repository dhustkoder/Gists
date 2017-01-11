#ifndef VECTORS_H_
#define VECTORS_H_
#include <math.h>

static const float kPI = 3.14159265359;

struct Vector2f {
	float x, y;
};

struct Vector3f {
	float x, y, z;
};

typedef struct Vector2f vec2f_t;
typedef struct Vector3f vec3f_t;


inline vec2f_t add_vec2f(const vec2f_t a, const vec2f_t b)
{
	const vec2f_t result = { a.x + b.x, a.y + b.y };
	return result;
}


inline vec2f_t sub_vec2f(const vec2f_t a, const vec2f_t b)
{
	const vec2f_t result = { a.x - b.x, a.y - b.y };
	return result;
}


inline float dot_vec2f(const vec2f_t a, const vec2f_t b)
{
	return (a.x * b.x) + (a.y * b.y);
}


inline vec2f_t unit_vec2f(const vec2f_t v, const float len)
{
	const vec2f_t result = { v.x / len, v.y / len };
	return result;
}


inline vec2f_t neg_vec2f(const vec2f_t v)
{
	const vec2f_t result = { -v.x, -v.y };
	return result;
}


inline float len_vec2f(const vec2f_t v)
{
	return sqrtf((v.x * v.x) + (v.y * v.y));
}





inline vec3f_t add_vec3f(const vec3f_t a, const vec3f_t b)
{
	const vec3f_t result = { a.x + b.x, a.y + b.y, a.z + b.z };
	return result;
}


inline vec3f_t sub_vec3f(const vec3f_t a, const vec3f_t b)
{
	const vec3f_t result = { a.x - b.x, a.y - b.y, a.z - b.z };
	return result;
}


inline vec3f_t cross_vec3f(const vec3f_t a, const vec3f_t b)
{
	const vec3f_t result = {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x)
	};

	return result;
}


inline float dot_vec3f(const vec3f_t a, const vec3f_t b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}


inline vec3f_t unit_vec3f(const vec3f_t v, const float len)
{
	const vec3f_t result = { v.x / len, v.y / len, v.z / len };
	return result;
}


inline vec3f_t neg_vec3f(const vec3f_t v)
{
	const vec3f_t result = { -v.x, -v.y, -v.z };
	return result;
}


inline float len_vec3f(const vec3f_t v)
{
	return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}



#endif