#include <stdio.h>

char s[10000], * c;

int main()
{
	while (gets(s) != NULL)
	{
		c = s - 1;
		while (*(++c))
			*c -= 7;
		puts(s);
	}
	return 0;
}