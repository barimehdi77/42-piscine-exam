/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:17:31 by exam              #+#    #+#             */
/*   Updated: 2017/11/14 11:40:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_nbr_len(int nb, int base)
{
	int i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	cpy = (char*)malloc(sizeof(char) * len);
	if (cpy == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	int		s;
	int		len;
	char	*radix;
	char	*result;

	i = 0;
	s = 0;
	len = 0;
	radix = "0123456789ABCDEF";
	if (value == 0)
		return (ft_strdup("0"));
	if (base == 10 && value == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbr_len(value, base);
	if (base == 10 && value < 0)
		s = 1;
	result = (char*)malloc(sizeof(char) * (len + s + 1));
	if (result == NULL)
		return (NULL);
	if (s == 1)
	{
		result[0] = '-';
		len++;
	}
	result[len] = '\0';
	if (value < 0)
		value *= -1;
	while (len > s)
	{
		result[len - 1] = radix[value % base];
		value /= base;
		len--;
	}
	return (result);
}
