/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:54:11 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/19 22:08:58 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

char	*ft_parse_flag(t_flag *flag, va_list list)
{
	ft_putchar(flag->opt);
	ft_putnbr(flag->width);
	ft_putnbr(flag->prec);
	ft_putchar(flag->conv);
	(void)list;
	return ("\n");
}
