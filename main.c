/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:03:44 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/25 23:37:11 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{

	printf("[%d]\n",        ft_printf("%10x",10));
	printf("[%d]\n",           printf("%10x",10));

	return (0);
}
