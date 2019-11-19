/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 02:07:31 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/19 15:43:15 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	ft_get_opt(const char *format, char conv)
{
	while (*format != conv)
	{
		if (*format == '-')
			return ('-');
		if (*format == '0')
			return ('0');
		format++;
	}
	return ('n');
}
