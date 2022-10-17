/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:51:11 by hahadiou          #+#    #+#             */
/*   Updated: 2022/10/14 20:05:11 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(const char *s, va_list ap, int i)
{
	int	len;

	len = 0;
	if (s[i] == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (s[i] == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (s[i] == 'd')
		len += ft_putnbr(va_arg(ap, int));
	else if (s[i] == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (s[i] == 'u')
		len += ft_putnbr_u(va_arg(ap, unsigned int));
	else if (s[i] == '%')
		len += ft_print_percent();
	else if (s[i] == 'x')
		len += ft_print_hex(va_arg(ap, unsigned int), 'x');
	else if (s[i] == 'X')
		len += ft_print_hex(va_arg(ap, unsigned int), 'X');
	else if (s[i] == 'p')
		len += ft_print_addr(va_arg(ap, unsigned long));
	return (len);
}
