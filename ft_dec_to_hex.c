/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:21:58 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/17 12:17:35 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_dec_to_hex(unsigned int nbr)
{
	unsigned int	rem;
	char			tab[100];
	int				i;

	i = 0;
	while (nbr)
	{
		rem = nbr % 16;
		tab[i++] = ((rem < 10) ? rem + 48 : rem + 55);
		nbr /= 16;
	}
	tab[i] = '\0';
	return (ft_strrev(tab));
}