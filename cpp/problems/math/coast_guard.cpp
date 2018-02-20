#include <cstdio>
#include <cmath>

int main()
{
	int d, vf, vg;
	while (std::scanf("%d %d %d", &d, &vf, &vg) != EOF) {
		const double ft = 12.00 / vf;
		const double gt = std::sqrt(144.00 + (d * d)) / vg;
		std::printf("%c\n", (ft >= gt ? 'S' : 'N'));
	}

	return 0;
}

