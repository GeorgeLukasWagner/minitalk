# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/11 15:19:27 by gwagner           #+#    #+#              #
#    Updated: 2024/08/14 11:59:01 by gwagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR      = srcs/
INC_DIR      = includes/
PRINTF_DIR   = $(INC_DIR)ft_printf/

SERVER_SRCS  = $(SRC_DIR)server.c
CLIENT_SRCS  = $(SRC_DIR)client.c
BSERVER_SRCS = $(SRC_DIR)server_bonus.c
BCLIENT_SRCS = $(SRC_DIR)client_bonus.c
INCL         = $(INC_DIR)minitalk.h
SERVER_OBJS  = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS  = $(CLIENT_SRCS:.c=.o)
BSERVER_OBJS = $(BSERVER_SRCS:.c=.o)
BCLIENT_OBJS = $(BCLIENT_SRCS:.c=.o)

CC           = cc -Wall -Werror -Wextra -I $(INCL)
RM           = rm -f
CLIENT_NAME  = client
SERVER_NAME  = server
NAME         = $(SERVER_NAME) $(CLIENT_NAME)

all: $(NAME)

$(NAME):			$(SERVER_OBJS) $(CLIENT_OBJS)
					$(MAKE) -sC $(PRINTF_DIR)
					$(CC) $(CLIENT_OBJS) -o $(CLIENT_NAME) $(PRINTF_DIR)libftprintf.a
					$(CC) $(SERVER_OBJS) -o $(SERVER_NAME) $(PRINTF_DIR)libftprintf.a

clean   : 
					$(MAKE) clean -sC $(PRINTF_DIR)
					$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(BSERVER_OBJS) $(BCLIENT_OBJS)
		  
fclean  :			clean
					$(MAKE) fclean -sC $(PRINTF_DIR)
					$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re      :			fclean $(NAME)

bonus   :			$(BSERVER_OBJS) $(BCLIENT_OBJS)
					$(MAKE) -sC $(PRINTF_DIR)
					$(CC) $(BCLIENT_OBJS) -o $(CLIENT_NAME) $(PRINTF_DIR)libftprintf.a
					$(CC) $(BSERVER_OBJS) -o $(SERVER_NAME) $(PRINTF_DIR)libftprintf.a

.PHONY  :			all clean fclean re