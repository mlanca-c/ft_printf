# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 14:40:53 by mlanca-c          #+#    #+#              #
#    Updated: 2021/03/12 14:27:37 by mlanca-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	=	./libft/libft.a
NAME	=	libftprintf.a
SRCS	=	ft_printf.c \
			sources/set_params.c \
			sources/get_case.c \
			sources/case_c.c \
			sources/case_s.c \
			sources/case_percentage.c \
			sources/case_p.c \
			sources/case_d.c \
			sources/case_u.c \
			sources/case_x.c \
			sources/case_percentage.c \
			sources/handle_width.c \
			sources/arg_conversions.c
OBJS	=	$(SRCS:.c=.o)
INCS	=	-I includes
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
CLIB	=	ar -rc
RM		=	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCS)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp $(LIBFT) $(NAME)
	$(CLIB) $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
