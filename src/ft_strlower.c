/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:10:19 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/26 15:51:05 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strlower(const char *str)
{
	int		len;
	char	*str2;
	int		i;

	i = 0;
	len = ft_strlen(str) + 1;
	str2 = ft_calloc(len, 1);
	while (str[i])
	{
		str2[i] = ft_tolower(str[i]);
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
