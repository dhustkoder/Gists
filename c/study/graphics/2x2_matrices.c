#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct Matrix2x2f {
	float data[2][2];
};

typedef struct Matrix2x2f mat2f_t;


inline mat2f_t add_scalar_mat2f(const mat2f_t m, const float scalar)
{
	const mat2f_t result = {{
		{ m.data[0][0] + scalar, m.data[0][1] + scalar },
		{ m.data[1][0] + scalar, m.data[1][1] + scalar }
	}};

	return result;
}


inline mat2f_t sub_scalar_mat2f(const mat2f_t m, const float scalar)
{
	const mat2f_t result = {{
		{ m.data[0][0] - scalar, m.data[0][1] - scalar },
		{ m.data[1][0] - scalar, m.data[1][1] - scalar }
	}};

	return result;
}


inline mat2f_t mul_scalar_mat2f(const mat2f_t m, const float scalar)
{
	const mat2f_t result = {{
		{ m.data[0][0] * scalar, m.data[0][1] * scalar },
		{ m.data[1][0] * scalar, m.data[1][1] * scalar }
	}};
	return result;
}


inline mat2f_t add_mat2f(const mat2f_t a, const mat2f_t b)
{
	const mat2f_t result = {{
		{ a.data[0][0] + b.data[0][0], a.data[0][1] + b.data[0][1] },
		{ a.data[1][0] + b.data[1][0], a.data[1][1] + b.data[1][1] }
	}};

	return result;
}


inline mat2f_t sub_mat2f(const mat2f_t a, const mat2f_t b)
{
	const mat2f_t result = {{
		{ a.data[0][0] - b.data[0][0], a.data[0][1] - b.data[0][1] },
		{ a.data[1][0] - b.data[1][0], a.data[1][1] - b.data[1][1] }
	}};

	return result;
}


inline mat2f_t mul_mat2f(const mat2f_t a, const mat2f_t b)
{
	const mat2f_t result = {{
		{ a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0],
		  a.data[0][0] * b.data[0][1] + a.data[0][1] * b.data[1][1] },

		{ a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0],
		  a.data[1][0] * b.data[0][1] + a.data[1][1] * b.data[1][1] }
	}};

	return result;
}


int main(int argc, char** argv)
{
	if (argc < 10) {
		printf("Give 2 2x2 matrices and a scalar, Ex:"
		       "%s a1 a2 a3 a4 b1 b2b b3 b4\n", argv[0]);
		return EXIT_SUCCESS;
	}

	const mat2f_t a = {{
		{ strtof(argv[1], NULL), strtof(argv[2], NULL) },
		{ strtof(argv[3], NULL), strtof(argv[4], NULL) }
	}};

	const mat2f_t b = {{
		{ strtof(argv[5], NULL), strtof(argv[6], NULL) },
		{ strtof(argv[7], NULL), strtof(argv[8], NULL) }
	}};

	const float scalar = strtof(argv[9], NULL);

	const mat2f_t ab_sum = add_mat2f(a, b);
	const mat2f_t ab_sub = sub_mat2f(a, b);
	const mat2f_t ab_mul = mul_mat2f(a, b);
	const mat2f_t a_add_scalar = add_scalar_mat2f(a, scalar);
	const mat2f_t b_add_scalar = add_scalar_mat2f(b, scalar);
	const mat2f_t a_sub_scalar = sub_scalar_mat2f(a, scalar);
	const mat2f_t b_sub_scalar = sub_scalar_mat2f(b, scalar);
	const mat2f_t a_mul_scalar = mul_scalar_mat2f(a, scalar);
	const mat2f_t b_mul_scalar = mul_scalar_mat2f(b, scalar);

	printf("MATRICES:\n"
	       "a => |%f %f|\n"
	       "     |%f %f|\n\n"
	       "b => |%f %f|\n"
	       "     |%f %f|\n\n"
	       "Scalar => %f\n\n"
	       "a + b = |%f %f|\n"
	       "        |%f %f|\n\n"
	       "a - b = |%f %f|\n"
	       "        |%f %f|\n\n"
	       "a * b = |%f %f|\n"
	       "        |%f %f|\n\n"
	       "a + scalar = |%f %f|\n"
	       "             |%f %f|\n\n"
	       "a - scalar = |%f %f|\n"
	       "             |%f %f|\n\n"
	       "b + scalar = |%f %f|\n"
	       "             |%f %f|\n\n"
	       "b - scalar = |%f %f|\n"
	       "             |%f %f|\n\n"
	       "a * scalar = |%f %f|\n"
	       "             |%f %f|\n\n"
	       "b * scalar = |%f %f|\n"
	       "             |%f %f|\n\n",

	       a.data[0][0], a.data[0][1],
	       a.data[1][0], a.data[1][1],

	       b.data[0][0], b.data[0][1],
	       b.data[1][0], b.data[1][1],

	       scalar,

	       ab_sum.data[0][0], ab_sum.data[0][1],
	       ab_sum.data[1][0], ab_sum.data[1][1],

	       ab_sub.data[0][0], ab_sub.data[0][1],
	       ab_sub.data[1][0], ab_sub.data[1][1],

	       ab_mul.data[0][0], ab_mul.data[0][1],
	       ab_mul.data[1][0], ab_mul.data[1][1],

	       a_add_scalar.data[0][0], a_add_scalar.data[0][1],
	       a_add_scalar.data[1][0], a_add_scalar.data[1][1],

	       a_sub_scalar.data[0][0], a_sub_scalar.data[0][1],
	       a_sub_scalar.data[1][0], a_sub_scalar.data[1][1],

	       b_add_scalar.data[0][0], b_add_scalar.data[0][1],
	       b_add_scalar.data[1][0], b_add_scalar.data[1][1],

	       b_sub_scalar.data[0][0], b_sub_scalar.data[0][1],
	       b_sub_scalar.data[1][0], b_sub_scalar.data[1][1],

	       a_mul_scalar.data[0][0], a_mul_scalar.data[0][1],
	       a_mul_scalar.data[1][0], a_mul_scalar.data[1][1],
	       
	       b_mul_scalar.data[0][0], b_mul_scalar.data[0][1],
	       b_mul_scalar.data[1][0], b_mul_scalar.data[1][1]);


	return EXIT_SUCCESS;
}


