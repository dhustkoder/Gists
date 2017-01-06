#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vector2f {
	float x, y;
} vec2f_t;


inline float get_magnitude(const vec2f_t* const v)
{
	return sqrtf((v->x * v->x) + (v->y * v->y));
}

inline vec2f_t get_diff(const vec2f_t* const from, const vec2f_t* const to)
{
	const vec2f_t result = { .x = to->x - from->x, .y = to->y - from->y };
	return result;
}

int main(int argc, char** argv)
{
	if (argc < 5) {
		printf("Usage: %s x y x y\n"
		       "Give 2 2D vectors values.\n", argv[0]);
		return EXIT_SUCCESS;
	}

	const vec2f_t a = { .x = strtof(argv[1], NULL), .y = strtof(argv[2], NULL) };
	const vec2f_t b = { strtof(argv[3], NULL), strtof(argv[4], NULL) };

	const vec2f_t a_to_b_diff = get_diff(&a, &b);
	const vec2f_t b_to_a_diff = { .x = -a_to_b_diff.x, .y = -a_to_b_diff.y };

	const float a_magnitude = get_magnitude(&a);
	const float b_magnitude = get_magnitude(&b);
	const float diff_magnitude = get_magnitude(&a_to_b_diff);

	printf("a => (%.2f, %.2f)\n"
	       "b => (%.2f, %.2f)\n"
	       "a magnitude => %.2f\n"
	       "b magnitude => %.2f\n"
	       "a to b diff => (%.2f, %.2f)\n"
	       "b to a diff => (%.2f, %.2f)\n"
	       "diff magnitude => %.2f\n",
	       a.x, a.y,
	       b.x, b.y,
	       a_magnitude,
	       b_magnitude,
	       a_to_b_diff.x, a_to_b_diff.y,
	       b_to_a_diff.x, b_to_a_diff.y,
	       diff_magnitude);


	return EXIT_SUCCESS;
}



