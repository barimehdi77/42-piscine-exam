/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 10:06:36 by exam              #+#    #+#             */
/*   Updated: 2018/12/27 12:38:30 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_nbrlen(unsigned int nbr, int base)
{
	if (nbr >= (unsigned int) base)
		return (1 + ft_nbrlen(nbr / base, base));
	else
		return (1);
}

void	ft_convert_base(char **str, unsigned int nbr, int base)
{
	char			*strbase;

	strbase = "0123456789ABCDEF";
	if (nbr < (unsigned int) base)
		*(*str)++ = *(strbase + nbr);
	else
	{
		ft_convert_base(str, nbr / base, base);
		ft_convert_base(str, nbr % base, base);
	}
}

char	*ft_itoa_base(int value, int base)
{
	char			*str;
	int				len;
	unsigned int	nbr;
	int				sign;

	if (base < 2 || base > 16)
		return (NULL);
	len = 0;
	sign = 1;
	if (value < 0)
	{
		if (base == 10)
		{
			sign = -1;
			len++;
		}
		nbr = value * -1;
	}
	else
		nbr = value;
	len += ft_nbrlen(nbr, base);
	if (!(str = (char *) malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (sign < 0)
		*str++ = '-';
	ft_convert_base(&str, nbr, base);
	*str = '\0';
	return (str - len);
}
