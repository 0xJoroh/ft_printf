/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:04:32 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/17 12:28:29 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# ifndef _LIBFT_H_
#  define _LIBFT_H_
#  include "libft/libft.h"
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
size_t	ft_numlen(size_t nbr);
char	*ft_strlower(char *str);
char	*ft_dec_to_hex(unsigned int nbr);

#endif
