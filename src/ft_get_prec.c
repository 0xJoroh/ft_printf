/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 02:11:14 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/19 15:18:41 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_get_prec(const char *format, va_list list)
{
	int		i;

	i = 0;
	while (!ft_isconv(*++format))
		if (*format == '.')
			break ;
	if (ft_isconv(*format))
		return (0);
	if (*++format == '*')
		return (((i = va_arg(list, int)) > 0) ? i : 0);
	return (((i = ft_atoi(format)) > 0) ? i : 0);
}
