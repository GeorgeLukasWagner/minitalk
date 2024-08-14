/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:04:28 by gwagner           #+#    #+#             */
/*   Updated: 2024/06/14 14:39:24 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static int	rec_print(unsigned long n, const char *base)
{
	int	len;

	len = 0;
	if (n > 15)
		len += rec_print(n / 16, base);
	len += ft_putchar_i(*(base + (n % 16)));
	return (len);
}

int	ft_putaddr(void *ptr)
{
	unsigned long	n;
	int				len;
	char const		*base;

	if (!ptr)
		return (ft_puts_i("(nil)"));
	n = (unsigned long)ptr;
	base = "0123456789abcdef";
	len = ft_puts_i("0x");
	len += rec_print(n, base);
	return (len);
}
