#ifndef MATRICES_H_
#define MATRICES_H_

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

#endif
