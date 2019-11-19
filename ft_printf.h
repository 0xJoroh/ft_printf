/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:29:40 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/19 02:49:14 by mait-si-         ###   ########.fr       */
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
	char		*string;
	char		*opt;
	int			width;
	int			prec;
	char		conv;
}				t_flag;

int				ft_printf(const char *format, ...);
char			*ft_dtoh(unsigned int nbr);
int				ft_putlower(char *str);
int				ft_putadd(void *add);
char			*ft_itoa_u(unsigned int n);
int				ft_putconv(const char *format, va_list list);
void			ft_set_flag(const char *format, t_flag *flag);
char			*ft_get_string(const char *format, char *conv);
char			*ft_parse_flag(t_flag *flag);
char			*ft_get_opt(t_flag *flag);
int				ft_get_width(t_flag *flag);
int				ft_get_prec(t_flag *flag);
int				ft_get_output(const char *format, va_list list);

#endif
