/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:29:40 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/23 23:08:14 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef _LIBFT_H_
#  define _LIBFT_H_
#  include "src/libft/libft.h"
# else
#  include <stdlib.h>
#  include <unistd.h>
# endif

# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flag
{
	char		opt;
	int			width;
	int			prec;
	char		conv;
	char		*content;
}				t_flag;

int				ft_printf(const char *format, ...);
char			*ft_dtoh(unsigned int nbr);
char			*ft_get_add(void *add);
char			*ft_utoa(unsigned int n);
void			ft_set_flag(const char *format, t_flag *flag, va_list list);
void			ft_parse_flag(t_flag *flag);
int				ft_get_output(const char *format, va_list list);
int				ft_isconv(char c);
char			*ft_strlower(const char *str);
char			*ft_atoc(int nbr);
size_t			ft_numlen(size_t nbr);
void			ft_parse_width(t_flag *flag);

#endif
