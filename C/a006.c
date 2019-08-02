#include <stdio.h>
#include <math.h>

int a, b, c, s, sr, x1, x2;

int main()
{
	while (scanf("%d %d %d", &a, &b, &c) == 3)
	{
		s = (b * b) - (4 * a * c);
		if (s < 0)
		{
			printf("No real root\n");
			continue;
		}
		sr = sqrt(s);
		x1 = (-b + sr) / (2 * a);
		x2 = (-b - sr) / (2 * a);
		if (sr)
		{
			printf("Two different roots x1=%d , x2=%d\n", x1, x2);
		}
		else
		{
			printf("Two same roots x=%d\n", x1);
		}
	}
	return 0;
}