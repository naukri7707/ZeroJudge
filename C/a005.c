#include <stdio.h>

int num[5], kase;

int main()
{
	scanf(" %d", &kase);
	while (kase--)
	{
		scanf(" %d %d %d %d", &num[0], &num[1], &num[2], &num[3]);

		if (num[1] - num[0] == num[3] - num[2])
		{
			num[4] = num[3] + num[1] - num[0];
		}
		else
		{
			num[4] = num[3] * num[1] / num[0];
		}
		printf("%d %d %d %d %d\n", num[0], num[1], num[2], num[3], num[4]);
	}
	return 0;
}