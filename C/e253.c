int add(int a, int b)
{
	while (b)
	{
		int ta = a ^ b, tb = (a & b) << 1;
		a = ta, b = tb;
	}
	return a;
}