/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:05:37 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/19 02:44:53 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_set_flag(const char *format, t_flag *flag)
{
	char	conv;

	flag->string = ft_get_string(&format, &conv);
	// flag->opt = ft_get_opt(&flag);
	// flag->width = ft_get_width(&flag);
	// flag->prec = ft_get_prec(&flag);
	flag->conv = conv;
}
