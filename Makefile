# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 14:40:53 by mlanca-c          #+#    #+#              #
#    Updated: 2021/03/04 14:54:39 by mlanca-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	=	libft/libft.a
NAME	=	libftprintf.a
SRCS	=	ft_printf.c
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
	$(MAKE) bonus -C libft
	cp $(LIBFT) $(NAME)
	$(CLIB) $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
