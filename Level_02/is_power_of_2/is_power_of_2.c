int		is_power_of_2(unsigned int n)
{
	unsigned long i;

	i = 1;
	while (i < 0xffffffff)
	{
		if (i == n)
			return (1);
		i *= 2;
	}
	return (0);
}
