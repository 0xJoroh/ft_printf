/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 02:22:26 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/20 18:44:05 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int				ft_check_conv(const char **format)
{
	while (**format == '%')
		format++;
	if (ft_isalpha(**format) && ft_isconv(**(format + 1)))
		return (1);
	return (0);
}

static void		ft_init_flag(t_flag *flag)
{
	flag->opt = 0;
	flag->width = 0;
	flag->prec = -1;
	flag->conv = 0;
	flag->content = 0;
}

void			ft_put_struct(t_flag flag)
{
	ft_putstr("\n\tconversion\t:\t");ft_putchar(flag.conv);
	ft_putstr("\n\twidth\t\t:\t");ft_putnbr(flag.width);
	ft_putstr("\n\toption\t\t:\t");ft_putchar(flag.opt);
	ft_putstr("\n\tprecesion\t:\t");ft_putnbr(flag.prec);
	ft_putstr("\n\tcontent\t\t:\t");ft_putstr((char*)flag.content);
	ft_putstr("\n");
}

int				ft_get_output(const char *format, va_list list)
{
	int			counter;
	char		*str;
	t_flag		flag;

	counter = 0;
	// if (*(format + 1) == '\0')
	// 	break ;
	while (*format)
	{
		if (*format == '%')
			if (*(format + 1) == '\0')
				break ;
			else if (ft_check_conv(&format))
			{
				ft_init_flag(&flag);
				ft_set_flag(format, &flag, list);
				ft_put_struct(flag);
				// ft_putstr(str = ft_parse_flag(&flag));
				counter += (!ft_strlen(str) ? 1 : ft_strlen(str));
				while (*format != flag.conv)
					format++;
			}
			else
				counter += ft_putchar(*format);
		else
			counter += ft_putchar(*format);
		format++;
	}
	list = NULL;
	return (counter);
}
