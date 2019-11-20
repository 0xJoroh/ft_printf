/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:54:11 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/20 22:54:42 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

static char			*ft_flag_width(t_flag *flag)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = (flag->width > 0 ? flag->width : flag->width * -1);
	str = malloc(len + 1);
	if (flag->width > 0)
	{
		while (i < (len - ft_numlen(num)))
			str[i++] = ' ';
		ft_strcat(str, ft_itoa(num));
	}
	return (str);
}

void				ft_parse_flag(t_flag *flag)
{
	if (flag->opt == 'n' && flag->prec == -1 && flag->width == 0)
		ft_putstr(flag->content);
	if (flag->width != 0)
		ft_flag_width(flag);
}
