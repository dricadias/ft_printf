/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:31:22 by adias-do          #+#    #+#             */
/*   Updated: 2024/11/22 18:49:50 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	c;

	c = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		ft_putchar(*s);
		s++;
		c++;
	}
	return (c);
}

int	ft_putnbr(int n)
{
	int		len;
	long	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = nb * -1;
	}
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
	{
		len += ft_putchar(nb + '0');
	}
	return (len);
}

int	ft_putunbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
	{
		len += ft_putunbr(nb / 10);
		len += ft_putunbr(nb % 10);
	}
	else
	{
		len += ft_putchar(nb + '0');
	}
	return (len);
}

int	ft_hex(unsigned int dec, char t)
{
	int		c;

	c = 0;
	if (dec >= 16)
		c += ft_hex(dec / 16, t);
	if (dec % 16 < 10)
		c += ft_putchar((dec % 16) + 48);
	else
	{
		if (t == 'x')
			c += ft_putchar((dec % 16) + 87);
		if (t == 'X')
			c += ft_putchar((dec % 16) + 55);
	}
	return (c);
}
