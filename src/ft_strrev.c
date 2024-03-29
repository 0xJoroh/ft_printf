/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:45:16 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/26 15:50:48 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	helper;

	i = -1;
	size = ft_strlen(str) - 1;
	while (++i <= (size / 2))
	{
		helper = str[i];
		str[i] = str[size - i];
		str[size - i] = helper;
	}
	return (str);
}
