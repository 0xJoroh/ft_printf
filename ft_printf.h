/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:29:40 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/25 17:17:30 by macbookpro       ###   ########.fr       */
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
int				ft_parse_flag(t_flag flag);
int				ft_get_output(const char *format, va_list list);
int				ft_isconv(char c);
char			*ft_strlower(const char *str);
char			*ft_atoc(int nbr);
size_t			ft_numlen(size_t nbr);
char         	*ft_parse_prec(t_flag flag);
char			*ft_parse_width(t_flag flag);

#endif
