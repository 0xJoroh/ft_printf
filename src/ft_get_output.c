/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 02:22:26 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/20 22:50:07 by mait-si-         ###   ########.fr       */
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
	// ft_putstr("\n\tconversion\t:\t");
	// ft_putchar(flag.conv);
	// ft_putstr("\n\twidth\t\t:\t");
	// ft_putnbr(flag.width);
	// ft_putstr("\n\toption\t\t:\t");
	// ft_putchar(flag.opt);
	// ft_putstr("\n\tprecesion\t:\t");
	// ft_putnbr(flag.prec);
	// ft_putstr("\n\tcontent\t\t:\t");
	// ft_putstr(flag.content);
	// ft_putstr("\n");
// }

int				ft_get_output(const char *format, va_list list)
{
	int			counter;
	t_flag		flag;

	counter = 0;
	while (*format)
	{
		if (*format == '%')
			if (*(format + 1) == '%' || !ft_isconv(*(format + 1)))
				counter += ft_putchar(*format++);
			else if (*(format + 1) == '\0')
				break ;
			else
			{
				ft_init_flag(&flag);
				ft_set_flag(format, &flag, list);
				// ft_put_struct(flag);
				ft_parse_flag(&flag);
				counter += (ft_strlen(flag.content) ? \
				ft_strlen(flag.content) : 1);
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
