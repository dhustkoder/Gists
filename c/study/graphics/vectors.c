#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef struct Vector2f {
	float x, y;
} vec2f_t;


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



inline float mag_vec2f(const vec2f_t v)
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
	const vec2f_t ab_sub = sub_vec2f(a, b);

	const vec2f_t diff = diff_vec2f(a, b);
	const vec2f_t negdiff = neg_vec2f(diff);

	const float a_mag = mag_vec2f(a);
	const float b_mag = mag_vec2f(b);
	const float diff_mag = mag_vec2f(diff);
	const vec2f_t a_unit = unit_vec2f(a, a_mag);
	const vec2f_t b_unit = unit_vec2f(b, b_mag);

	printf("a => (%.2f, %.2f)\n"
	       "b => (%.2f, %.2f)\n"
	       "a magnitude => %.2f\n"
	       "b magnitude => %.2f\n"
	       "a to b diff => (%.2f, %.2f)\n"
	       "b to a diff => (%.2f, %.2f)\n"
	       "diff magnitude => %.2f\n"
	       "a + b => (%.2f, %.2f)\n"
	       "a - b => (%.2f, %.2f)\n"
	       "unit from a => (%.2f, %.2f)\n"
	       "unit from b => (%.2f, %.2f)\n",
	       a.x, a.y,
	       b.x, b.y,
	       a_mag, b_mag,
	       diff.x, diff.y,
	       negdiff.x, negdiff.y,
	       diff_mag,
	       ab_sum.x, ab_sum.y,
	       ab_sub.x, ab_sub.y,
	       a_unit.x, a_unit.y,
	       b_unit.x, b_unit.y);


	return EXIT_SUCCESS;
}



