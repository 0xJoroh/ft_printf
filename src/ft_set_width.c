/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:01:53 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/22 14:10:22 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char			*ft_set_width(t_flag *flag)
{
	char	*str;
	int		len;
	int		i;
	char	c;

	i = 0;
	len = flag->width - ft_strlen(flag->content);
	if (len > 0)
	{
		str = malloc(len);
		if (flag->opt == '0')
			if (flag->conv == '%' || flag->conv == 'd' || flag->conv == 'i' ||
			flag->conv == 'u' || flag->conv == 'x' || flag->conv == 'X')
				c = '0';
			else
				c = ' ';
		else
			c = ' ';
		if (flag->content[0] == '-' && c == '0')
		{
			flag->content = ft_memmove(flag->content, flag->content + 1,
			ft_strlen(flag->content));
			str[i++] = '-';
		}
		while (len--)
			str[i++] = c;
		str[i] = '\0';
	}
	else
		str = ft_calloc(1, 1);
	return (str);
}

void				ft_parse_width(t_flag *flag)
{
	char	*str;

	str = malloc(flag->width - ft_strlen(flag->content));
	str = ft_strdup(ft_set_width(flag));
	if (flag->opt == '-')
		flag->content = ft_strjoin(flag->content, str);
	else
		flag->content = ft_strjoin(str, flag->content);
	ft_putstr(flag->content);
}
