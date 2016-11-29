#include <stdio.h>
#include <math.h>

int main()
{
	const long double g = 9.80665;
	const long double pi = 3.14159;
	long double high, angle, speed, rad, aux1, aux2, res;
	int i, n, p1, p2;
	while (scanf("%Lf %d %d %d", &high, &p1, &p2, &n) != EOF) {
		aux1 = (2 * high) / g;
		for (i = 0; i < n; ++i) {
			scanf("%Lf %Lf", &angle, &speed);
			rad = (angle / 180.00) * pi;
			aux2 = (speed * sinl(rad)) / g;
			res = (speed * cosl(rad)) * (sqrtl(aux1 + powl(aux2, 2)) + aux2);
			printf("%.5Lf -> %cUCK\n", res,
			       (res >= p1 && res <= p2) ? 'D' : 'N');
		}
	}

	return 0;
}

