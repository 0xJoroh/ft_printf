/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:51:58 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/17 16:25:30 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list list;
	int		counter;
	char	*str;
	char	num;

	counter = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
			if (*++format == '%')
				ft_putchar('%');
			else if (*format == '\0')
				break;
			else if (*format == 's')
			{
				ft_putstr(str = va_arg(list, char*));
				counter += ft_strlen(str) - 1;
			}
			else if (*format == 'c')
				ft_putchar(va_arg(list, int));
			else if (*format == 'i' || *format == 'd')
			{
				ft_putnbr(num = va_arg(list, int));
				counter += ft_numlen(num) - 1;
			}
			else if (*format == 'x' || *format == 'X')
			{
				if (*format == 'x')
					ft_putlower(str = ft_dec_to_hex(va_arg(list, int)));
				else
					ft_putstr(str = ft_dec_to_hex(va_arg(list, int)));
				counter += ft_strlen(str) - 1;
			}
			else if (*format == 'p')
				counter += ft_putadd(va_arg(list, int *)) + 1;
			else
				ft_putchar(*format);
		else
			ft_putchar(*format);
		counter++;
		format++;
	}
	va_end(list);
	return (counter);
}
