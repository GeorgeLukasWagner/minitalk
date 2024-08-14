/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:30:37 by gwagner           #+#    #+#             */
/*   Updated: 2024/06/14 14:34:53 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned long n, int format)
{
	char			*base;
	unsigned int	num;
	int				i;

	if (format == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	num = (unsigned int)n;
	if (num > 15)
		i += ft_putnbr_hexa(num / 16, format);
	i += ft_putchar_i(*(base + (num % 16)));
	return (i);
}
