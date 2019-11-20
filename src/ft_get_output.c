/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 02:22:26 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/20 02:37:33 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** Printing out format's characters one by one with mondatory flags
*/

static void		ft_init_flag(t_flag *flag)
{
	flag->opt = 0;
	flag->width = 0;
	flag->prec = 0;
	flag->conv = 0;
}

int				ft_get_output(const char *format, va_list list)
{
	int			counter;
	char		*str;
	t_flag		flag;

	counter = 0;
	while (*format)
	{
		if (*format == '%')
			if (*(format + 1) == '\0')
				break ;
			else
			{
				ft_init_flag(&flag);
				ft_set_flag(format++, &flag, list);
				ft_putstr(str = ft_parse_flag(&flag, list));
				counter += (!ft_strlen(str) ? 1 : ft_strlen(str));
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
