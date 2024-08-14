/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:07:29 by gwagner           #+#    #+#             */
/*   Updated: 2024/06/14 14:34:56 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static int	nbr_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr < 1)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_i(int n)
{
	long	ln;
	long	divider;
	char	c;

	ln = n;
	if (ln < 0)
	{
		write(1, "-", 1);
		ln = ln * -1;
	}
	divider = 1;
	while (divider * 10 <= ln)
		divider = divider * 10;
	while (divider)
	{
		c = ln / divider + '0';
		write(1, &c, 1);
		ln = ln % divider;
		divider = divider / 10;
	}
	return (nbr_len(n));
}
