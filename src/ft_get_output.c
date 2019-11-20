/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 02:22:26 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/20 21:06:56 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_init_flag(t_flag *flag)
{
	flag->opt = 0;
	flag->width = 0;
	flag->prec = -1;
	flag->conv = 0;
	flag->content = 0;
}

// void			ft_put_struct(t_flag flag)
// {
// 	ft_putstr("\n\tconversion\t:\t");ft_putchar(flag.conv);
// 	ft_putstr("\n\twidth\t\t:\t");ft_putnbr(flag.width);
// 	ft_putstr("\n\toption\t\t:\t");ft_putchar(flag.opt);
// 	ft_putstr("\n\tprecesion\t:\t");ft_putnbr(flag.prec);
// 	ft_putstr("\n\tcontent\t\t:\t");ft_putstr((char*)flag.content);
// 	ft_putstr("\n");
// }

static int		ft_get_parsed(t_flag flag, const char *format, va_list list)
{
	char *str;

	ft_init_flag(&flag);
	ft_set_flag(format, &flag, list);
	ft_put_struct(flag);
	ft_putstr(str = ft_parse_flag(&flag));
	return ((!ft_strlen(str) ? 1 : ft_strlen(str)));
}

int				ft_get_output(const char *format, va_list list)
{
	int			counter;
	char		*str;
	t_flag		flag;

	counter = 0;
	while (*format)
	{
		if (*format++ == '%')
			if (*format == '%')
				counter += ft_putchar(*format);
			else if (*(format + 1) == '\0')
				break ;
			else
			{
				counter += ft_get_parsed(flag, format, list);
				while (*format != flag.conv)
					format++;
			}
		else
			counter += ft_putchar(*format);
		format++;
	}
	list = NULL;
	return (counter);
}
