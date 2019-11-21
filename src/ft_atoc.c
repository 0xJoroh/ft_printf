/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:31:54 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/21 18:38:07 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_atoc(int nbr)
{
	char	*str;

	if (!nbr)
		return ("");
	str = malloc(2);
	str[0] = nbr;
	if (!ft_isascii(nbr))
		return ("\0");
	str[1] = '\0';
	free(str);
	return (str);
}
