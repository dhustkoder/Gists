#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

static const float kPI = 3.141592;

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

	// calculate the sum and difference
	const vec2f_t ab_sum = add_vec2f(a, b);
	const vec2f_t ba_sub = sub_vec2f(b, a);

	// calculate the vectors length
	const float a_len = len_vec2f(a);
	const float b_len = len_vec2f(b);
	const float diff_len = len_vec2f(ba_sub);

	// calculate the vectors angle to each other
	const float dot_prod = dot_vec2f(a, b);
	const float radians = acosf(dot_prod / (a_len * b_len));
	const float degrees = radians * (180 / kPI);

	// this shall give the same result as above
	// but with the unit vectors, we don't need divide by lengths multiplied,
	// as their lengths must be equal to 1
	const vec2f_t a_unit = unit_vec2f(a, a_len);
	const vec2f_t b_unit = unit_vec2f(b, b_len);
	const float unit_dot_prod = dot_vec2f(a_unit, b_unit);
	const float unit_radians = acosf(unit_dot_prod);
	const float unit_degrees = unit_radians * (180 / kPI);


	printf("VECTORS:\n"
	       "a => (%.2f, %.2f)\n"
	       "b => (%.2f, %.2f)\n"
	       "\nLENGTHS:\n"
	       "||a|| => %.2f\n"
	       "||b|| => %.2f\n"
	       "\nSUM AND DIFFERENCE:\n"
	       "a + b => (%.2f, %.2f)\n"
	       "b - a => (%.2f, %.2f)\n"
	       "||b - a|| => %.2f\n"
	       "\nUNITS:\n"
	       "unit a => (%.2f, %.2f)\n"
	       "unit b => (%.2f, %.2f)\n"
	       "\nANGLE:\n"
	       "dot product => %.2f\n"
	       "radians => %f\n"
	       "degrees => %.2f\n"
	       "\nANGLE CALCULATED FROM A AND B UNITS:\n"
	       "dot product => %.2f\n"
	       "radians => %f\n"
	       "degrees => %.2f\n",
	       a.x, a.y,
	       b.x, b.y,
	       a_len, b_len,
	       ab_sum.x, ab_sum.y,
	       ba_sub.x, ba_sub.y,
	       diff_len,
	       a_unit.x, a_unit.y,
	       b_unit.x, b_unit.y,
	       dot_prod, radians, degrees,
	       unit_dot_prod, unit_radians, unit_degrees);


	return EXIT_SUCCESS;
}



