# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 14:40:53 by mlanca-c          #+#    #+#              #
#    Updated: 2021/06/23 12:52:47 by mlanca-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	# Library Name #
NAME	=	libftprintf.a

	# Mandatory and Bonus Part Variables #
SRCS_H	=	ft_putchar.c ft_putstr.c ft_free_function.c ft_ftoa.c \
			ft_roundup_number.c
SRCS	=	ft_printf.c set_params.c handle_flags.c get_case.c case_c.c \
			case_s.c case_percentage.c case_p.c case_d.c case_u.c case_x.c \
			case_percentage.c case_n.c case_f.c case_g.c case_e.c case_o.c \
			handle_width.c arg_conversions.c handle_number.c handle_double.c \
			$(SRCS_H)
OBJS	=	$(SRCS:.c=.o)

	# Libft #
LIBFT	=	./libft/libft.a

	# Includes flag for compilation #
INC			= 	-Ilibft/stack/ -Ilibft/ -I.

	# Compiling Variables #
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
CLIB		=	ar -rc
RM			=	rm -f

	# Debugger #
ifeq ($(DEBUG), 1)
	D_FLAG	=	-g
endif

	# Fsanitize #
ifeq ($(SANITIZE), 1)
	D_FLAG	=	-fsanitize=address -g
endif

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

%.o: %.c
	@ $(CC) $(CFLAG) -c $< -o $(<:.c=.o) $(INC)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	@ $(MAKE) re -C ./libft
	@ cp $(LIBFT) $(NAME)
	@ $(CLIB) $(NAME) $(OBJS)
	@printf "$(_SUCCESS) $(NAME) ready.\n"

clean:
	@ $(MAKE) clean -C ./libft
	@ $(RM) $(OBJS)complete
	@printf "$(_INFO) object files removed.\n"

fclean: clean
	@ $(MAKE) fclean -C ./libft
	@ $(RM) $(NAME)
	@printf "$(_INFO) $(NAME) removed.\n"

re: fclean all

.PHONY: all clean fclean re bonus
