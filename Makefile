# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 18:00:53 by mait-si-          #+#    #+#              #
#    Updated: 2019/11/27 11:52:43 by mait-si-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libftprintf.a

SRCS		=		ft_atoc.c			\
					ft_bzero.c			\
					ft_dtoh.c			\
					ft_get_output.c		\
					ft_isascii.c		\
					ft_isdigit.c		\
					ft_memmove.c		\
					ft_parse_flag.c		\
					ft_parse_width.c	\
					ft_putchar.c		\
					ft_set_flag.c		\
					ft_strdup.c			\
					ft_strlen.c			\
					ft_strrev.c			\
					ft_tolower.c		\
					ft_utoa.c			\
					ft_atoi.c			\
					ft_calloc.c			\
					ft_get_add.c		\
					ft_isalpha.c		\
					ft_isconv.c			\
					ft_itoa.c			\
					ft_numlen.c			\
					ft_parse_prec.c		\
					ft_printf.c			\
					ft_putstr.c			\
					ft_strcmp.c			\
					ft_strjoin.c		\
					ft_strlower.c		\
					ft_substr.c			\
					ft_toupper.c

OBJS		=		$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(NAME)

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all