#include <unistd.h>
#include <stdlib.h>

int		brackets(char *src, int i)
{
	int count;
	int direction;

	count = 0;
	if (src[i] == '[')
		direction = 1;
	else if (src[i] == ']')
		direction = -1;
	while (src[i] != '\0')
	{
		if (src[i] == '[')
			count++;
		else if (src[i] == ']')
			count--;
		if ((src[i] == '[' || src[i] == ']') && count == 0)
			return (i);
		i += direction;
	}
	return (0);
}

void	brainfuck(char *src)
{
	int i;
	int i2;
	char *ptr;

	i = 0;
	i2 = 0;
	ptr = (char*)malloc(sizeof(char) * 2048);
	while (src[i] != '\0')
	{
		if (src[i] == '>')
			i2++;
		else if (src[i] == '<')
			i2--;
		else if (src[i] == '+')
			ptr[i2]++;
		else if (src[i] == '-')
			ptr[i2]--;
		else if (src[i] == '.')
			write(1, &ptr[i2], 1);
		else if ((src[i] == '[' && !(ptr[i2])) || (src[i] == ']' && ptr[i2]))
			i = brackets(src, i);
		i++;
	}	
}

int		main(int ac, char **av)
{
	if (ac > 1)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
