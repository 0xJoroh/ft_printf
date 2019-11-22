/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:22:48 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/22 14:22:49 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char				*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	nbr;
	unsigned int	i;
	unsigned int	size;

	nbr = n;
	size = ft_numlen(nbr);
	i = 0;
	if (!(str = (char*)malloc(size + 1)))
		return (0);
	while (nbr >= 10)
	{
		str[i++] = (char)(nbr % 10 + 48);
		nbr /= 10;
	}
	str[i++] = (char)(nbr % 10 + 48);
	str[i] = '\0';
	return (ft_strrev(str));
}
