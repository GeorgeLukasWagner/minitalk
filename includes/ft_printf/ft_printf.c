/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:49:51 by gwagner           #+#    #+#             */
/*   Updated: 2024/06/14 14:34:42 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static int	print_format(char conspf, va_list argp)
{
	int	count;

	count = 0;
	if (conspf == 'c')
		count += ft_putchar_i(va_arg(argp, int));
	else if (conspf == 's')
		count += ft_puts_i(va_arg(argp, char *));
	else if (conspf == 'p')
		count += ft_putaddr(va_arg(argp, void *));
	else if (conspf == 'd' || conspf == 'i')
		count += ft_putnbr_i(va_arg(argp, int));
	else if (conspf == 'u')
		count += ft_putnbr_us(va_arg(argp, unsigned int));
	else if (conspf == 'x')
		count += ft_putnbr_hexa(va_arg(argp, unsigned int), 0);
	else if (conspf == 'X')
		count += ft_putnbr_hexa(va_arg(argp, unsigned int), 1);
	else if (conspf == '%')
		count += write(1, "%", 1);
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		count;

	va_start(argp, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), argp);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(argp);
	return (count);
}
