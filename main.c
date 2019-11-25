/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:03:44 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/25 17:52:16 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	// printf("[%d]\n", ft_printf("%s", ""));
	// printf("[%d]\n\n",    printf("%s", ""));

	// printf("[%d]\n", ft_printf("[%------*c]", 3, 100));
	// printf("[%d]\n\n",  printf("[%------*c]", 3, 100));

	// printf("[%d]\n", ft_printf("[%-*p]", -100, (void*)INT32_MAX));
	// printf("[%d]\n",    printf("[%-*p]", -100, (void*)INT32_MAX));

	// printf("[%d]\n", ft_printf("[%3p]", (void*)100));
	// printf("[%d]\n",    printf("[%3p]", (void*)100));

	// printf("[%d]\n", ft_printf("hello %u !", -977564442));
	// printf("[%d]\n\n",    printf("hello %u !", -977564442));

	// printf("[%d]\n", ft_printf("hello %x !", -977564442));
	// printf("[%d]\n\n",    printf("hello %x !", -977564442));

	// printf("[%d]\n", ft_printf("hello %X !", -977564442));
	// printf("[%d]\n\n",    printf("hello %X !", -977564442));

	// printf("[%d]\n", ft_printf("hello %d !", -977564442));
	// printf("[%d]\n\n",    printf("hello %d !", -977564442));

	// printf("[%d]\n", ft_printf("--------%%----%%%%----%%%%%%--------"));
	// printf("[%d]",    printf("--------%%----%%%%----%%%%%%--------"));

	// printf("[%d]", ft_printf("\n----[%i]----[%s]----[%c]----[%d]----[%x]----[%X]----[%u]----[%%]----[%%%%]----[%%%%%%]----[%p]", INT32_MAX, NULL, 104, INT32_MIN, -98732442, 3668592, UINT32_MAX, (void*)UINT64_MAX));
	// printf("[%d]",    printf("\n----[%i]----[%s]----[%c]----[%d]----[%x]----[%X]----[%u]----[%%]----[%%%%]----[%%%%%%]----[%p]", INT32_MAX, NULL, 104, INT32_MIN, -98732442, 3668592, UINT32_MAX, (void*)UINT64_MAX));

	// printf("\t[%d]\n",    ft_printf("%.*s", 2, NULL));
	// printf("\t[%d]\n",       printf("%.*s", 2, NULL));

	// printf("[%d]\n",  ft_printf("[%c]", 100));
	// printf("[%d]\n",     printf("[%c]", 100));

	printf("[%d]\n",        ft_printf("[%10.*s]", 2, NULL));
	printf("[%d]\n",        printf("[%10.*s]", 2, NULL));

	return (0);
}
