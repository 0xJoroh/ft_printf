/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:03:44 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/17 12:28:36 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{
	printf("\t\t\t[%d]\n", ft_printf("[%s - %c - %d - %i - %x - %X]", "hello", 'c', 12, 96, 5699, 5699));
	printf("\t\t\t[%d]", printf("[%s - %c - %d - %i - %x - %X]", "hello", 'c', 12, 96, 566699, 566699));
	// printf("%s", ft_strlower("1bJ324"));
	return (0);
}
