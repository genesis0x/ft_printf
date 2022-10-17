/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:59:16 by hahadiou          #+#    #+#             */
/*   Updated: 2022/10/14 20:04:16 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[++i])
		write(1, &s[i], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	len += ft_putchar(n % 10 + 48);
	return (len);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putnbr_u(unsigned long n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_u(n / 10);
	len += ft_putchar(n % 10 + 48);
	return (len);
}
