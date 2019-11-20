/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:03:44 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/20 22:51:45 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	// printf("[%d]\n", ft_printf("hello %s !", "world"));
	// printf("[%d]\n\n",    printf("hello %s !", "world"));

	// printf("[%d]\n", ft_printf("hello %c !", 0));
	// printf("[%d]\n\n",    printf("hello %c !", 0));

	// int x;
	// printf("[%d]\n", ft_printf("hello %p !", &x));
	// printf("[%d]\n\n",    printf("hello %p !", &x));

	// printf("[%d]\n", ft_printf("hello %u !", -977564442));
	// printf("[%d]\n\n",    printf("hello %u !", -977564442));

	// printf("[%d]\n", ft_printf("hello %x !", -977564442));
	// printf("[%d]\n\n",    printf("hello %x !", -977564442));

	// printf("[%d]\n", ft_printf("hello %X !", -977564442));
	// printf("[%d]\n\n",    printf("hello %X !", -977564442));

	// printf("[%d]\n", ft_printf("hello %d !", -977564442));
	// printf("[%d]\n\n",    printf("hello %d !", -977564442));

	// ft_printf("--------------%s------------%d", "5", -2);
	int x;
	// printf("[%d]\n", ft_printf("--------%%----%%%%----%%%%%%--------"));
	// printf("[%d]",    printf("--------%%----%%%%----%%%%%%--------"));
	ft_printf("\n----[%i]----[%s]----[%c]----[%d]----[%x]----[%X]----[%u]----[%%]----[%%%%]----[%%%%%%]----[%p]", INT32_MAX, NULL, 104, INT32_MIN, -98732442, 3668592, UINT32_MAX, &x);
	   printf("\n----[%i]----[%s]----[%c]----[%d]----[%x]----[%X]----[%u]----[%%]----[%%%%]----[%%%%%%]----[%p]", INT32_MAX, NULL, 104, INT32_MIN, -98732442, 3668592, UINT32_MAX, &x);

	return (0);
}
