#include <stdlib.h>
#include <stdio.h>
#include "vectors.h"



int main(int argc, char** argv)
{
	if (argc < 7) {
		printf("Give 2 3D vectors: %s x y z x y z\n", argv[0]);
		return EXIT_SUCCESS;
	}

	const vec3f_t a = { 
		strtof(argv[1], NULL),
		strtof(argv[2], NULL),
		strtof(argv[3], NULL)
	};

	const vec3f_t b = {
		strtof(argv[4], NULL),
		strtof(argv[5], NULL),
		strtof(argv[6], NULL)
	};

	// sum and diff
	const vec3f_t ab_sum = add_vec3f(a, b);
	const vec3f_t ba_sub = sub_vec3f(b, a);

	// lengths
	const float a_len = len_vec3f(a);
	const float b_len = len_vec3f(b);

	// angle
	const float dot_prod = dot_vec3f(a, b);
	const float radians = acosf(dot_prod / (a_len * b_len));
	const float degrees = radians * (180 / kPI);

	vec3f_t cross_prod = { 0, 0, 0 };

	// if not parallel
	if (degrees != 0)
		cross_prod = cross_vec3f(a, b);	

	printf("VECTORS:\n"
	       "a => (%f, %f, %f)\n"
	       "b => (%f, %f. %f)\n"
	       "\nSUM AND DIFF:\n"
	       "a + b = (%f, %f, %f)\n"
	       "b - a = (%f, %f, %f)\n"
	       "\nLENGTHS:\n"
	       "a => %f\n"
	       "b => %f\n"
	       "\nANGLE:\n"
	       "dot product => %f\n"
	       "radians => %f\n"
	       "degrees => %.2f\n"
	       "\nCROSS PRODUCT:\n"
	       "a x b => (%f, %f, %f)\n",
	       a.x, a.y, a.z, b.x, b.y, b.z,
	       ab_sum.x, ab_sum.y, ab_sum.z,
	       ba_sub.x, ba_sub.y, ba_sub.z,
	       a_len, b_len,
	       dot_prod, radians, degrees,
	       cross_prod.x, cross_prod.y, cross_prod.z);

	return EXIT_SUCCESS;
}
