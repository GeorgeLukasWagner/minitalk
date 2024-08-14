# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 11:56:37 by gwagner           #+#    #+#              #
#    Updated: 2024/06/14 14:34:26 by gwagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT		= ./libft/libft.a
SRCS		= ft_printf.c ft_putchar_i.c ft_putnbr_hexa.c ft_putnbr_i.c ft_putnbr_us.c ft_puts_i.c ft_putaddr.c
INCL        = ft_printf.h
OBJS        :=  $(SRCS:.c=.o)
CC          = cc
RM          = rm -f
CFLAGS      = -Wall -Werror -Wextra -I $(INCL)
NAME        = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
	
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re