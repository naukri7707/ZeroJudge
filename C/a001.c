#include <stdio.h>

char s[1000];

int main()
{
	while (scanf(" %s" , s) == 1)
	{
		printf("hello, %s\n", s);
	}
	return 0;
}