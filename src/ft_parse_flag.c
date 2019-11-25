/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:54:11 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/25 14:26:40 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

void				ft_simple_conv(t_flag flag)
{
	if (flag.conv == 'c')
		ft_putchar(flag.content[0]);
	else
		ft_putstr(flag.content);
}

int				ft_parse_flag(t_flag flag)
{
	if (flag.width == 0 && flag.prec == -1)
		ft_simple_conv(flag);
	// else if (flag->width == 0 && flag->prec != -1)
	// 	flag->content = ft_parse_prec(flag);
	// else if (flag->width != 0 && flag->prec == -1)
	// 	flag->content = ft_parse_width(flag);
	// else if (flag->width != 0 && flag->prec != -1)
	// 	flag->content = ft_mixte(flag);
	return (ft_strlen(flag.content));
}
