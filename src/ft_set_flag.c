/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:05:37 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/20 16:30:05 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		ft_get_conv(const char *format)
{
	int		i;

	i = 1;
	if (!*format)
		return (0);
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
	while (*format != conv && *format != '.')
	{
		if (*format == '-')
			return ('-');
		if (*format == '0')
			return ('0');
		format++;
	}
	return ('n');
}

static int		ft_get_width(const char *format, va_list list, char opt)
{
	int	output;

	if (*++format == '*')
	{
		output = va_arg(list, int);
		if (output < 0 && opt == '-')
			return (-output);
		return (output);
	}
	return (ft_atoi(format));
}

static int		ft_get_prec(const char *format, va_list list)
{
	int		i;

	i = 0;
	while (!ft_isconv(*++format))
		if (*format == '.')
			break ;
	if (ft_isconv(*format))
		return (0);
	if (*++format == '*')
		return (((i = va_arg(list, int)) > 0) ? i : 0);
	return (((i = ft_atoi(format)) > 0) ? i : 0);
}

void			ft_set_flag(const char *format, t_flag *flag, va_list list)
{
	flag->conv = ft_get_conv(format);
	flag->opt = ft_get_opt(format, flag->conv);
	flag->width = ft_get_width(format, list, flag->opt);
	flag->prec = ft_get_prec(format, list);
	flag->content = (flag->conv == '%' ? NULL : va_arg(list, void*));
}
