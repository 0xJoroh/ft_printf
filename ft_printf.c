/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:51:58 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/19 14:56:09 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char			*ft_parse_flag(t_flag *flag)
// {
// 	char	*output;

// 	output = "...";
// 	(t_flag)*flag;
// 	return (output);
// }

int				ft_printf(const char *format, ...)
{
	va_list	list;
	int		counter;

	va_start(list, format);
	counter = ft_get_output(format, list);
	va_end(list);
	return (counter);
}
