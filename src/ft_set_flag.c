/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:05:37 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/24 10:50:29 by mait-si-         ###   ########.fr       */
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

static int		ft_get_width(const char *format, va_list list, char opt)
{
	int	output;

	format++;
	while (*format != '.' && !ft_isalpha(*format))
	{
		if (*format == '*')
		{
			output = va_arg(list, int);
			if (output < 0 && opt == '-')
				return (-output);
			return (output);
		}
		if (ft_isdigit(*format) && *format != '0')
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

char			*ft_set_prec(t_flag *flag)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (flag->prec == 0 && !ft_strcmp(flag->content, "0"))
		return (flag->content = "");
	len = flag->prec - ft_strlen(flag->content);
	if (len >= 0)
	{
		str = malloc(len);
		if (ft_atoi(flag->content) < 0)
		{
			flag->content = ft_memmove(flag->content, flag->content + 1,
			ft_strlen(flag->content));
			str[i++] = '-';
			len++;
		}
		while (len--)
			str[i++] = '0';
		str[i] = '\0';
		return (ft_strjoin(str, flag->content));
	}
	return (ft_calloc(1, 1));
}

char			*ft_get_cont(t_flag *flag, va_list list)
{
	if (flag->conv == '%')
		return (flag->content = "%");
	flag->content = ft_get_arg(list, flag->conv);
	if (!flag->content)
		flag->content = "(null)";
	if ((flag->conv == 'd' || flag->conv == 'i' || flag->conv == 'x' ||
	flag->conv == 'X' || flag->conv == 'u'))
	{
		if (flag->prec == 0 && !ft_strcmp(flag->content, "0"))
			return (flag->content = "");
		if (flag->prec > -1)
			if (flag->prec >= (int)ft_strlen(flag->content))
				return (flag->content = ft_set_prec(flag));
	}
	if (flag->prec > 0 && flag->conv == 's')
		return (flag->content = ft_substr(flag->content, 0, flag->prec));
	if (flag->prec == 0 && flag->conv == 's')
		return (flag->content = "");
	if (flag->prec == 0 && flag->conv == 'p' && flag->width == 0 &&
	flag->content[2] == '0')
		return (flag->content = "0x");
	return (flag->content);
}

void			ft_set_flag(const char *format, t_flag *flag, va_list list)
{
	flag->conv = ft_get_conv(format);
	flag->opt = ft_get_opt(format, flag->conv);
	flag->width = ft_get_width(format, list, flag->opt);
	if (flag->width < 0)
	{
		flag->width *= -1;
		flag->opt = '-';
	}
	flag->prec = ft_get_prec(format, flag->conv, list);
	flag->content = ft_get_cont(flag, list);
}
