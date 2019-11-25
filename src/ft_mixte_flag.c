/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mixte_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:20:08 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/25 18:47:40 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_mixte(t_flag flag)
{
	flag.content = ft_strdup(ft_parse_prec(flag));
	flag.content = ft_strdup(ft_parse_width(flag));
	return (flag.content);
}
