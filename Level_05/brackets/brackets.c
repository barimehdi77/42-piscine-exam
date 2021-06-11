/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:59:36 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/19 12:27:05 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		matching(char b1, char b2)
{
	if (b1 == '(' && b2 == ')')
		return (1);
	if (b1 == '[' && b2 == ']')
		return (1);
	if (b1 == '{' && b2 == '}')
		return (1);
	return (0);
}

int		brackets(char *str, char *stack)
{
	int i;
	int top;

	i = 0;
	top = -1;
	while (str[i] != '\0')
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			top++;
			stack[top] = str[i];
		}
		if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (!stack[top])
				return (0);
			else if (!matching(stack[top], str[i]))
				return (0);
			else
			{
				stack[top] = 0;
				top--;
			}
		}
		i++;
	}
	if (stack[top] == 0)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int	 i;
	char stack[512];

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (brackets(av[i], stack))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
