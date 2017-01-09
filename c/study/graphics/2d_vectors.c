#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

struct Vector2f {
	float x, y;
};

typedef struct Vector2f vec2f_t;



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


inline vec2f_t unit_vec2f(const vec2f_t v, const float mag)
{
	const vec2f_t result = { v.x / mag, v.y / mag };
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



inline vec2f_t diff_vec2f(const vec2f_t from, const vec2f_t to)
{
	return sub_vec2f(to, from);
}



int main(int argc, char** argv)
{
	if (argc < 5) {
		printf("Usage: %s x y x y\n"
		       "Give 2 2D vectors values.\n", argv[0]);
		return EXIT_SUCCESS;
	}

	const vec2f_t a = { strtof(argv[1], NULL), strtof(argv[2], NULL) };
	const vec2f_t b = { strtof(argv[3], NULL), strtof(argv[4], NULL) };

	const vec2f_t ab_sum = add_vec2f(a, b);
	const vec2f_t ba_sub = sub_vec2f(b, a);

	const float a_len = len_vec2f(a);
	const float b_len = len_vec2f(b);
	const float diff_len = len_vec2f(ba_sub);

	const vec2f_t a_unit = unit_vec2f(a, a_len);
	const vec2f_t b_unit = unit_vec2f(b, b_len);

	const float dot_prod = dot_vec2f(a, b);
	const float radians = acos(dot_prod / (a_len * b_len));
	const float degrees = radians * (180 / 3.141592);

	printf("a => (%.2f, %.2f)\n"
	       "b => (%.2f, %.2f)\n"
	       "||a|| => %.2f\n"
	       "||b|| => %.2f\n"
	       "a + b => (%.2f, %.2f)\n"
	       "b - a => (%.2f, %.2f)\n"
	       "||b - a|| => %.2f\n"
	       "unit from a => (%.2f, %.2f)\n"
	       "unit from b => (%.2f, %.2f)\n"
	       "dot product between a and b => %.2f\n"
	       "angle between a and b => %f radians\n"
	       "angle between a and b => %.1f degrees\n",
	       a.x, a.y,
	       b.x, b.y,
	       a_len, b_len,
	       ab_sum.x, ab_sum.y,
	       ba_sub.x, ba_sub.y,
	       diff_len,
	       a_unit.x, a_unit.y,
	       b_unit.x, b_unit.y,
	       dot_prod, radians, degrees);


	return EXIT_SUCCESS;
}



