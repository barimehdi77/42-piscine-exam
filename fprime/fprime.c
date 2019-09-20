/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeqdar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:09:07 by mmeqdar           #+#    #+#             */
/*   Updated: 2019/02/08 15:59:33 by mmeqdar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void    fprime(int n)
{
	int i;
	int n1;
	int n2;
	n1 = 1;
	n2 = n;
	i = 2;
	if (n == 1)
		printf("%d", n);
	else
	{
	while (n > 0)
	{
		while (n % i >= 0 )
		{
			if (n % i == 0)
			{
				printf("%d", i);
				n = n / i;
				break ;
			}
			i++;
		}
		n1 *=i;
		if (n1 != n2)
			printf("*");
		else 
			break ;
	}
	}
}

int main (int argc, char **argv)
{
	int n;
	(void)argc;
	if (argc == 2)
	{
	n = atoi(argv[1]);
	fprime(n);
	}
	printf ("\n");
	return 0;
}
