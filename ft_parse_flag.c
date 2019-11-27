/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:54:11 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/27 11:44:37 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_putstring(t_flag flag)
{
	int	len;

	len = 0;
	if (flag.opt == '-')
	{
		len += ft_putchar(0);
		len += ft_putstr(flag.content);
	}
	else
	{
		len += ft_putstr(flag.content);
		len += ft_putchar(0);
	}
	return (len - 1);
}

int				ft_parse_flag(t_flag flag)
{
	int		len;

	len = (flag.content[0] == 0 && flag.conv == 'c') ? 1 : 0;
	if (flag.width <= 1 && flag.conv == 'c')
		return (ft_putchar(flag.content[0]));
	else if (flag.width == 0 && flag.prec != -1)
		flag.content = ft_parse_prec(flag);
	else if (flag.width != 0 && flag.prec == -1 &&
	flag.width > (int)ft_strlen(flag.content))
		flag.content = ft_parse_width(flag);
	else if (flag.width != 0 && flag.prec != -1)
	{
		flag.content = ft_strdup(ft_parse_prec(flag));
		flag.content = ft_strdup(ft_parse_width(flag));
	}
	if (len)
		len += ft_putstring(flag);
	else
		len += ft_putstr(flag.content);
	return (len);
}
