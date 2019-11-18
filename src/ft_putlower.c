/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:51:54 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/18 18:31:36 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putlower(char *str)
{
	int len;

	len = 0;
	if (str)
		while (*str != '\0')
			len += ft_putchar(ft_tolower(*str++));
	else
	{
		write(1, "(NULL)", 6);
		len = 6;
	}
	return (len);
}
