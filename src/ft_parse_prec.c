/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:05:33 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/26 15:51:05 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	char	*ft_get_num_content(t_flag flag)
{
	int		len;
	int		i;
	char	*str;

	if (flag.prec == 0 && !ft_strcmp(flag.content, "0"))
		return ("");
	if (flag.prec >= (int)ft_strlen(flag.content))
	{
		i = 0;
		len = flag.prec - ft_strlen(flag.content);
		str = ft_calloc(len, 1);
		if (flag.content[0] == '-')
		{
			flag.content = ft_memmove(flag.content, flag.content + 1,
			ft_strlen(flag.content));
			str[i++] = '-';
			len++;
		}
		while (len--)
			str[i++] = '0';
		str[i] = '\0';
		return (ft_strjoin(str, flag.content));
	}
	return (flag.content);
}

char			*ft_parse_prec(t_flag flag)
{
	if (flag.conv == 's' || flag.conv == 'c')
	{
		if (flag.prec == -1 && flag.conv == 'c')
			return (ft_calloc(1, 1));
		if (flag.prec == 0 && flag.conv == 's')
			return (ft_calloc(1, 1));
		if (flag.prec < (int)ft_strlen(flag.content) && flag.prec > 0)
			return (ft_substr(flag.content, 0, flag.prec));
	}
	if (flag.conv == 'd' || flag.conv == 'i' || flag.conv == 'u' ||
	flag.conv == 'x' || flag.conv == 'X')
		return (ft_get_num_content(flag));
	return (flag.content);
}
