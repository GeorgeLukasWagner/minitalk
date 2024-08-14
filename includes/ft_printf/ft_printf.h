/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:57:18 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/04 13:58:44 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_puts_i(char *str);
int	ft_putnbr_us(unsigned int n);
int	ft_putnbr_i(int n);
int	ft_putnbr_hexa(unsigned long n, int format);
int	ft_putchar_i(char c);
int	ft_printf(const char *format, ...);
int	ft_putaddr(void *ptr);

#endif