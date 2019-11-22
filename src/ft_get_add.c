/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:05:13 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/22 11:36:21 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*tohex(unsigned long long nbr)
{
	unsigned long long				rem;
	char							*tab;
	int								i;

	i = 0;
	tab = malloc(100);
	if (nbr == 0)
		tab[i++] = '0';
	while (nbr)
	{
		rem = nbr % 16;
		tab[i++] = ft_tolower(((rem < 10) ? rem + 48 : rem + 55));
		nbr /= 16;
	}
	tab[i] = '\0';
	return (ft_strrev(tab));
}

char			*ft_get_add(void *add)
{
	char		*output;
	char		*str;
	int			len;
	int			i;

	i = 2;
	str = tohex((unsigned long long)add);
	len = ft_strlen(str) + 3;
	output = malloc(len);
	output[0] = '0';
	output[1] = 'x';
	while (i < len)
		output[i++] = *str++;
	output[i] = '\0';
	return (output);
}
