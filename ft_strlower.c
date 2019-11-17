/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:15:03 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/17 12:28:26 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char    *ft_strlower(char *str)
{
    int		len;
	char	*str2;

    len = ft_strlen(str);
	str2 = (char *)malloc(len + 1);
    while (*str)
        *str2++ = ft_tolower(*str++);
    *str2 = '\0';
	free(str2 - len);
    return (str2 - len);
}