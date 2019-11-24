/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:54:11 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/24 14:30:24 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

void				ft_parse_flag(t_flag *flag)
{
	if (flag->width == 0)
		if (flag->conv == 'c')
			ft_putchar(flag->content[0]);
		else
			ft_putstr(flag->content);
	else if (flag->prec == -1)
		ft_parse_width(flag);
	// else if (flag->prec > -1)
	// 	ft_parse_prec(flag);
	else
		ft_putstr(flag->content);

	// if (flag->opt == 'n' && flag->prec == -1 && flag->width == 0)
	// 	if (flag->conv == 'c')
	// 		ft_putchar(flag->content[0]);
	// 	else
	// 		ft_putstr(flag->content);
	// else if (flag->prec == -1)
	// 	ft_parse_width(flag);
	// // else if (flag->prec > -1)
	// // 	ft_parse_prec(flag);
	// else
	// 	ft_putstr(flag->content);
}
