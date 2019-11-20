/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:54:11 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/20 16:45:55 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

static char		*ft_simple_conv(char conv, void *content)
{
	if (conv == 'p')
		return (ft_get_add((int*)content));
	else if (conv == 'x' || conv == 'X')
		if (conv == 'x')
			return (ft_strlower(ft_dtoh((int)content)));
		else
			return (ft_dtoh((int)content));
	else if (conv == 'i' || conv == 'd')
		return (ft_itoa((int)content));
	else if (conv == 'u')
		return (ft_utoa((unsigned int)content));
	else if (conv == 'c')
		return (ft_atoc((int)content));
	else if (conv == 's')
		return ((char*)content);
	if (conv == '%')
		return ("%");
	else
		return ("(null)");
}

// static char			*ft_flag_width(t_flag *flag, va_list list)
// {
// 	char	*str;
// 	int		i;
// 	int		len;
// 	char	*arg;

// 	i = 0;
// 	arg = va_arg(list, char*);
// 	len = (flag->width > 0 ? flag->width : flag->width * -1);
// 	str = malloc(len + 1);
// 	if (flag->width > 0)
// 	{
// 		while (i < (len - ft_numlen(num)))
// 			str[i++] = ' ';
// 		ft_strcat(str, ft_itoa(num));
// 	}
// 	return (str);
// }

char			*ft_parse_flag(t_flag *flag)
{
	if (flag->opt == 'n' && flag->prec == 0 && flag->width == 0)
		return (ft_simple_conv(flag->conv, flag->content));
	// if (flag->width != 0)
	// 	return (ft_flag_width(flag, list));
	return ("(null)");
}
