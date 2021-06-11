#include <unistd.h>

int		ft_to_lower(char c, char d)
{
	if (c >= 'A' && c <= 'Z')
	{
		if (d != ' ' && d != '\t' && d != '\0')
			return (1);
	}
	return (0);
}

int		ft_to_upper(char c, char d)
{
	if (c >= 'a' && c <= 'z')
	{
		if (d == ' ' || d == '\t' || d == '\0')
			return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int i;
	int i2;

	i = 0;
	if (ac > 1)
	{
		while (i < ac)
		{
			i++;
			i2 = 0;
			while (av[i][i2] != '\0')
			{
				if (ft_to_upper(av[i][i2], av[i][i2 + 1]))
					av[i][i2] -= 32;
				else if (ft_to_lower(av[i][i2], av[i][i2 + 1]))
					av[i][i2] += 32;
				write(1, &av[i][i2], 1);
				i2++;
			}
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
