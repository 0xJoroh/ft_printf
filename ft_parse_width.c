/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:37:32 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/27 11:44:37 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			ft_zero_space(t_flag flag)
{
	if (flag.opt == '0' && flag.prec <= -1)
		if (flag.conv == '%' || flag.conv == 'd' || flag.conv == 'i' ||
		flag.conv == 'u' || flag.conv == 'x' || flag.conv == 'X')
			return ('0');
	return (' ');
}

static char			*ft_set_width(t_flag flag)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = flag.width - ft_strlen(flag.content) + 1;
	if (flag.conv == 'c' && flag.content[0] == 0)
		len--;
	if (len > 0)
	{
		str = ft_calloc(len, 1);
		if (flag.content[0] == '-' && ft_zero_space(flag) == '0')
		{
			flag.content = ft_memmove(flag.content, flag.content + 1,
			ft_strlen(flag.content));
			str[i++] = '-';
		}
		while (--len)
			str[i++] = ft_zero_space(flag);
		str[i] = '\0';
	}
	else
		str = ft_calloc(1, 1);
	return (str);
}

char				*ft_parse_width(t_flag flag)
{
	char	*str;
	int		len;

	len = flag.width - ft_strlen(flag.content);
	str = ft_calloc(len, 1);
	str = ft_strdup(ft_set_width(flag));
	if (flag.opt == '-')
		flag.content = ft_strjoin(flag.content, str);
	else
		flag.content = ft_strjoin(str, flag.content);
	return (flag.content);
}
