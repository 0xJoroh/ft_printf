/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:54:11 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/25 21:47:35 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_parse_flag(t_flag flag)
{
	if (flag.width == 0 && flag.conv == 'c' && flag.prec == -1)
		return (ft_putchar(flag.content[0]));
	else if (flag.width == 0 && flag.prec != -1)
		flag.content = ft_parse_prec(flag);
	else if (flag.width != 0 && flag.prec == -1 &&
	flag.width > (int)ft_strlen(flag.content))
		flag.content = ft_parse_width(flag);
	else if (flag.width != 0 && flag.prec != -1)
		flag.content = ft_mixte(flag);
	return (ft_putstr(flag.content));
}
