#include <unistd.h>

int		check_doubles(char *str, char c, int pos)
{
	int i;

	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int i;
	int i2;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i] != '\0')
		{
			i2 = 0;
			while (av[2][i2] != '\0')
			{
				if (av[1][i] == av[2][i2])
				{
					if (check_doubles(av[1], av[1][i], i))
					{
						write(1, &av[1][i], 1);
						break ;
					}
				}
				i2++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
