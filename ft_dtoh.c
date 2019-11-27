/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:19:29 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/27 11:44:37 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dtoh(unsigned int nbr)
{
	unsigned int	rem;
	char			*tab;
	int				i;

	i = 0;
	tab = (char*)ft_calloc(50, 1);
	if (nbr == 0)
		tab[i++] = '0';
	while (nbr)
	{
		rem = nbr % 16;
		tab[i++] = ((rem < 10) ? rem + 48 : rem + 55);
		nbr /= 16;
	}
	tab[i] = '\0';
	return (ft_strrev(tab));
}
