/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:05:37 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/25 12:24:30 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		ft_get_conv(const char *format)
{
	int		i;

	i = 1;
	if (!*format)
		return (0);
	while (format[i] == '%')
		i++;
	while (format[i])
		if (ft_isconv(format[i]))
			return (format[i]);
		else if (ft_isalpha(format[i]))
		{
			i = 0;
			break ;
		}
		else
			i++;
	return (0);
}

static char		ft_get_opt(const char *format, char conv)
{
	while (*++format != conv && *format != '.')
	{
		if (*format == '-')
			return ('-');
		if (*format == '0')
			return ('0');
		format++;
	}
	return ('n');
}

static int		ft_get_width(const char *format, va_list list, t_flag *flag)
{
	int	output;

	format++;
	while (*format != '.')
	{
		if (*format == '*')
		{
			output = va_arg(list, int);
			if (output < 0)
			{
				flag->opt = '-';
				return (-output);
			}
			return (output);
		}
		if (ft_isdigit(*format))
			return (ft_atoi(format));
		format++;
	}
	return (ft_atoi(format));
}

static int		ft_get_prec(const char *format, char conv, va_list list)
{
	++format;
	while (*format != conv && *format != '.')
		format++;
	if (*format == conv)
		return (-1);
	if (*format == '.')
		if (*++format == '*')
			return (va_arg(list, int));
	return (ft_atoi(format));
}

char			*ft_get_arg(va_list list, char conv)
{
	if (conv == 'd' || conv == 'i')
		return (ft_itoa(va_arg(list, int)));
	if (conv == 'x')
		return (ft_strlower(ft_dtoh(va_arg(list, int))));
	if (conv == 'X')
		return (ft_dtoh(va_arg(list, int)));
	if (conv == 'u')
		return (ft_utoa(va_arg(list, unsigned int)));
	if (conv == 'c')
		return (ft_atoc(va_arg(list, int)));
	if (conv == 's')
		return (va_arg(list, char*));
	if (conv == 'p')
		return (ft_get_add(va_arg(list, int*)));
	return (NULL);
}

void			ft_set_flag(const char *format, t_flag *flag, va_list list)
{
	flag->conv = ft_get_conv(format);
	flag->opt = ft_get_opt(format, flag->conv);
	flag->width = ft_get_width(format, list, flag);
	flag->prec = ft_get_prec(format, flag->conv, list);
	flag->content = ft_get_arg(list, flag->conv);
	if (!flag->content)
		flag->content = "(null)";
	if (flag->conv == '%')
		flag->content = "%";
}
