/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:55:21 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/18 20:55:39 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putconv(const char *format, va_list list)
{
	int counter;

	counter = 0;
	while (*format)
	{
		if (*format == '%')
			if (*++format == '\0')
				break ;
			else if (*format == 's')
				counter += ft_putstr(va_arg(list, char*));
			else if (*format == 'c')
				counter += ft_putchar(va_arg(list, int));
			else if (*format == 'i' || *format == 'd')
				counter += ft_putstr(ft_itoa(va_arg(list, int)));
			else if (*format == 'x' || *format == 'X')
				if (*format == 'x')
					counter += ft_putlower(ft_dtoh(va_arg(list, int)));
				else
					counter += ft_putstr(ft_dtoh(va_arg(list, int)));
			else if (*format == 'p')
				counter += ft_putadd(va_arg(list, int *));
			else if (*format == 'u')
				counter += ft_putstr(ft_itoa_u(va_arg(list, unsigned int)));
			else
				counter += ft_putchar(*format);
		else
			counter += ft_putchar(*format);
		format++;
	}
	return (counter);
}
