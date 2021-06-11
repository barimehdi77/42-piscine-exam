#include <unistd.h>

int		main(void)
{
	char even;
	char odd;

	even = 'B';
	odd = 'a';
	while (even <= 'Z')
	{
		write(1, &odd, 1);
		write(1, &even, 1);
		even += 2;
		odd += 2;
	}
	write(1, "\n", 1);
	return (0);
}
