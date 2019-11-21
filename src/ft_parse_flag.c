/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:54:11 by mait-si-          #+#    #+#             */
/*   Updated: 2019/11/21 23:57:47 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

// static char			*ft_flag_width(t_flag *flag)
// {
// 	char	*str;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	len = (flag->width > 0 ? flag->width : flag->width * -1);
// 	str = malloc(len + 1);
// 	if (flag->width > 0)
// 	{
// 		while (i < (len - ft_numlen(num)))
// 			str[i++] = ' ';
// 		ft_strcat(str, ft_itoa(num));
// 	}
// 	return (str);
// }

char				*ft_set_width(t_flag *flag)
{
	char	*str;
	int		len;
	int		i;
	char	c;

	i = 0;
	len = flag->width - ft_strlen(flag->content);
	str = ft_calloc(len, 1);
	c = ((flag->opt == '0') ? '0' : ' ');
	while (len--)
		str[i++] = c;
	str[i] = '\0';
	free(str);
	return (str);
}

void				ft_parse_c(t_flag *flag)
{
	char	*str;

	str = ft_strdup(ft_set_width(flag));
	if (flag->opt == '-')
		flag->content = ft_strjoin(flag->content, str);
	else
		flag->content = ft_strjoin(str, flag->content);
	ft_putstr(flag->content);
}

void				ft_parse_flag(t_flag *flag)
{
	if (flag->opt == 'n' && flag->prec == -1 && flag->width == 0)
		if (flag->conv == 'c')
			ft_putchar(flag->content[0]);
		else
			ft_putstr(flag->content);
	else if (flag->conv == 'c' || flag->conv == '%' || flag->conv == 'p')
		ft_parse_c(flag);
	else
		ft_putstr(flag->content);
}
