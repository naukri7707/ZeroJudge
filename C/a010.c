#include <stdio.h>

int num, count;
char output[10000], * oPt;

int main()
{
	while (scanf(" %d", &num) == 1)
	{
		oPt = output;
		for (int i = 2; i <= num; i++)
		{
			while (!(num % i))
			{
				num /= i;
				count++;
			}
			if (count)
			{
				if (count == 1)
					oPt += sprintf(oPt, "%d * ", i);
				else
					oPt += sprintf(oPt, "%d^%d * ", i, count);
				count = 0;
			}
		}
		*(oPt - 3) = 0;
		puts(output);
	}
	return 0;
}