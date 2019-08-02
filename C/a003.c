#include <stdio.h>

int m, d, s;

int main()
{
	while (scanf(" %d %d", &m, &d) == 2)
	{
		s = (m * 2 + d) % 3;
		if (s == 0)
		{
			puts("普通");
		}
		else if (s == 1)
		{
			puts("吉");
		}
		else
		{
			puts("大吉");
		}
	}
	return 0;
}