/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:51:28 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/19 02:43:21 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_isconv(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i')
		return (1);
	else if (c == 'p' || c == 'x' || c == 'X' || c == 'u' || c == '%')
		return (1);
	return (0);
}

char	*ft_get_string(const char *format, char *conv)
{
	int		i;

	i = 1;
	if (!format)
		return (NULL);
	while (format[i])
		if (ft_isconv(format[i]))
		{
			*conv = format[i];
			break ;
		}
		else if (ft_isalpha(format[i]))
		{
			i = 0;
			break ;
		}
		else
			i++;
	if (!format[i])
		i = 0;
	return (i ? ft_substr(format, 0, i + 1) : NULL);
}
