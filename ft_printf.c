/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:02:50 by adias-do          #+#    #+#             */
/*   Updated: 2024/11/22 18:50:43 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_args(va_list args, char t)
{
	int	count;

	count = 0;
	if (t == '%')
		count = ft_putchar(t);
	else if (t == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (t == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (t == 'p')
		count = ft_pointer(va_arg(args, void *));
	else if (t == 'd' || t == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (t == 'u')
		count = ft_putunbr(va_arg(args, unsigned int));
	else if (t == 'x' || t == 'X')
		count = ft_hex(va_arg(args, unsigned int), t);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
			len += ft_putchar(*format);
		if (*format == '%')
		{
			format++;
			if (*format)
				len += ft_args(args, *format);
		}
		format++;
	}
	va_end(args);
	return (len);
}
