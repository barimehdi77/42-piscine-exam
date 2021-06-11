#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	int	i;
	int	len;
	char	tmp;

	i = 0;
	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		len--;
		while (i < len)
		{
			tmp = av[1][i];
			av[1][i] = av[1][len];
			av[1][len] = tmp;
			i++;
			len--;
		}
		ft_putstr(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
