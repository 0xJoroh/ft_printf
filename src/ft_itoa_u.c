/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:47:37 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/18 18:42:50 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	ft_numlen(size_t nbr)
{
	unsigned int	size;

	size = 0;
	while (nbr >= 10)
	{
		nbr /= 10;
		++size;
	}
	return (size + 1);
}

char				*ft_itoa_u(unsigned int n)
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
