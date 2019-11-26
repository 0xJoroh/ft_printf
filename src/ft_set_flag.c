/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:05:37 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/26 15:51:05 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char			ft_get_conv(const char *format)
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

static char			ft_get_opt(const char *format, char conv)
{
	format++;
	while (*format != conv && *format != '.')
	{
		if (*format == '-')
			return ('-');
		else if (*format == '0')
			return ('0');
		if (ft_isdigit(*format) && *format != '0')
			return ('n');
		format++;
	}
	return ('n');
}

static int			ft_get_width(const char *format, va_list list, t_flag *flag)
{
	int	output;

	format++;
	while (*format != '.' && *format != flag->conv)
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
		if (ft_isdigit(*format) && *format != '0')
			return (ft_atoi(format));
		format++;
	}
	return (ft_atoi(format));
}

static char			*ft_get_arg(va_list list, t_flag flag)
{
	if (flag.conv == 'd' || flag.conv == 'i')
		return (ft_itoa(va_arg(list, int)));
	if (flag.conv == 'x')
		return (ft_strlower(ft_dtoh(va_arg(list, int))));
	if (flag.conv == 'X')
		return (ft_dtoh(va_arg(list, int)));
	if (flag.conv == 'u')
		return (ft_utoa(va_arg(list, unsigned int)));
	if (flag.conv == 'c')
		return (ft_atoc(va_arg(list, int)));
	if (flag.conv == 's')
		return (va_arg(list, char*));
	if (flag.conv == 'p')
		return (ft_get_add(va_arg(list, int*), flag.prec));
	return (NULL);
}

void				ft_set_flag(const char *format, t_flag *flag, va_list list)
{
	flag->conv = ft_get_conv(format);
	flag->opt = ft_get_opt(format, flag->conv);
	flag->width = ft_get_width(format++, list, flag);
	while (*format != flag->conv && *format != '.')
		format++;
	if (*format == flag->conv)
		flag->prec = -1;
	else if (*format == '.')
		if (*++format == '*')
			flag->prec = va_arg(list, int);
		else
			flag->prec = ft_atoi(format);
	else
		flag->prec = ft_atoi(format);
	flag->content = ft_get_arg(list, *flag);
	if (!flag->content)
		flag->content = "(null)";
	if (flag->conv == '%')
		flag->content = "%";
}
