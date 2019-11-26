/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:25:34 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/26 16:26:16 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

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
char			*ft_get_add(void *add, int prec);
char			*ft_utoa(unsigned int n);
void			ft_set_flag(const char *format, t_flag *flag, va_list list);
int				ft_parse_flag(t_flag flag);
int				ft_get_output(const char *format, va_list list);
int				ft_isconv(char c);
char			*ft_strlower(const char *str);
char			*ft_atoc(int nbr);
size_t			ft_numlen(size_t nbr);
char			*ft_parse_prec(t_flag flag);
char			*ft_parse_width(t_flag flag);

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
int				ft_putstr(char *str);
char			*ft_strrev(char *str);
int				ft_putchar(unsigned char c);

#endif
