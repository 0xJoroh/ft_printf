/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:54:11 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/20 02:38:15 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

static char		*ft_simple_conv(char conv, va_list list)
{
	if (conv == 'p')
		return (ft_get_add(va_arg(list, int *)));
	else if (conv == 'x' || conv == 'X')
		if (conv == 'x')
			return (ft_strlower(ft_dtoh(va_arg(list, int))));
		else
			return (ft_dtoh(va_arg(list, int)));
	else if (conv == 'i' || conv == 'd')
		return (ft_itoa(va_arg(list, int)));
	else if (conv == 'u')
		return (ft_itoa_u(va_arg(list, unsigned int)));
	else if (conv == '%')
		return ("%");
	else if (conv == 'c')
		return (ft_atoc(va_arg(list, int)));
	else if (conv == 's')
		return (va_arg(list, char*));
	else
		return ("(null)");
}

char			*ft_parse_flag(t_flag *flag, va_list list)
{
	if (flag->opt == 'n' && flag->prec == 0 && flag->width == 0)
		return (ft_simple_conv(flag->conv, list));
	else
		return ("(null)");
	return ("(null)");
}
