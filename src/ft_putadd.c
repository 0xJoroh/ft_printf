/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:05:13 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/18 14:42:08 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*tohex(unsigned long long nbr)
{
	int				rem;
	char			tab[100];
	int				i;

	i = 0;
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

int		ft_putadd(void *add)
{
	ft_putstr("0x");
	ft_putlower(tohex((unsigned long long)add));
	return (ft_strlen(tohex((unsigned long long)add)) + 2);
}
