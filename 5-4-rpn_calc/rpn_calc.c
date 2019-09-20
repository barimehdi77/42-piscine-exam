/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:02:01 by fpetras           #+#    #+#             */
/*   Updated: 2017/12/12 09:10:59 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		operate(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
	{
		if (b == 0)
			return (9942);
		return (a / b);
	}
	if (op == '%')
	{
		if (b == 0)
			return (9942);
		return (a % b);
	}
	return (9942);
}

int		isnum(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	return (0);
}

int		isop(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
		return (1);
	return (0);
}

int		rpn_calc(char *str, int *stack)
{
	int i;
	int top;

	i = 0;
	top = -1;
	while (str[i] != '\0')
	{
		if (isnum(&str[i]))
		{
			top++;
			stack[top] = atoi(&str[i]);
			while (str[i] != ' ' && str[i + 1] != '\0')
				i++;
		}
		if (isop(str[i]))
		{
			if (top > 0)
			{
				if ((stack[top - 1] = operate(stack[top - 1], stack[top],
				str[i])) == 9942)
					return (write(1, "Error\n", 6));
				top--;
			}
			else
				return (write(1, "Error\n", 6));
		}
		i++;
	}
	if (top == 0)
		printf("%d\n", stack[top]);
	else
		write(1, "Error\n", 6);
	return (0);
}

int		main(int ac, char **av)
{
	int stack[512];

	if (ac == 2)
		rpn_calc(av[1], stack);
	else
		write(1, "Error\n", 6);
	return (0);
}
