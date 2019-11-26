/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:09:24 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/26 15:50:48 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putstr(char *str)
{
	int len;

	len = ft_strlen(str);
	if (str)
		while (*str != '\0')
			write(1, &*str++, 1);
	else
	{
		write(1, "(null)", 6);
		len = 6;
	}
	return (len);
}
