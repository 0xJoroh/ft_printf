/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:12:23 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/25 12:07:08 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// char			*ft_set_prec(t_flag *flag)
// {
// 	char	*str;
// 	int		len;
// 	int		i;

// 	i = 0;
// 	if (flag->prec == 0 && !ft_strcmp(flag->content, "0"))
// 		return (flag->content = "");
// 	len = flag->prec - ft_strlen(flag->content);
// 	if (len >= 0)
// 	{
// 		str = malloc(len);
// 		if (ft_atoi(flag->content) < 0)
// 		{
// 			flag->content = ft_memmove(flag->content, flag->content + 1,
// 			ft_strlen(flag->content));
// 			str[i++] = '-';
// 			len++;
// 		}
// 		while (len--)
// 			str[i++] = '0';
// 		str[i] = '\0';
// 		return (ft_strjoin(str, flag->content));
// 	}
// 	return (ft_calloc(1, 1));
// }

// char			*ft_get_cont(t_flag *flag, va_list list)
// {
// 	if ((flag->conv == 'd' || flag->conv == 'i' || flag->conv == 'x' ||
// 	flag->conv == 'X' || flag->conv == 'u') && flag->prec != -1)
// 	{
// 		if (flag->prec == 0 && !ft_strcmp(flag->content, "0"))
// 			return (flag->content = "");
// 		if (flag->prec > -1)
// 			if (flag->prec >= (int)ft_strlen(flag->content))
// 				return (flag->content = ft_set_prec(flag));
// 	}
// 	if (flag->prec > 0 && flag->conv == 's')
// 		return (flag->content = ft_substr(flag->content, 0, flag->prec));
// 	if (flag->prec == 0 && flag->conv == 's')
// 		return (flag->content = "");
// 	if (flag->prec == 0 && flag->conv == 'p' && flag->width == 0 &&
// 	flag->content[2] == '0')
// 		return (flag->content = "0x");

// 	return (flag->content);
// }
