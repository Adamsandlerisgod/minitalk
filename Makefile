# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 16:08:21 by whendrik          #+#    #+#              #
#    Updated: 2023/08/14 20:36:32 by whendrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FLAGS
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -g

#Targlib name and dirs
NAME = minitalk
SERVER = server
CLIENT = client

SVR_SRCS = server.c
CLT_SRCS = client.c
UTILS = utils.c

B_SERVER = server_bonus
B_CLIENT = client_bonus
B_SVR_SRCS = server_bonus.c
B_CLT_SRCS = client_bonus.c

$(NAME): $(SERVER) $(CLIENT) $(B_CLIENT $(B_SERVER))

all: $(NAME)

$(SERVER):
	$(CC) $(C_FLAGS) $(UTILS) $(SVR_SRCS) -o $(SERVER)

$(CLIENT):
	$(CC) $(C_FLAGS) $(UTILS) $(CLT_SRCS) -o $(CLIENT)

bonus: 
	$(CC) $(C_FLAGS) $(UTILS) $(B_SVR_SRCS) -o $(B_SERVER)
	$(CC) $(C_FLAGS) $(UTILS) $(B_CLT_SRCS) -o $(B_CLIENT)

# Clean object files and executables
clean:
	$(RM) $(SERVER) $(CLIENT)

fclean: clean 
	$(RM) $(B_SERVER) $(B_CLIENT)

re: fclean all

rebonus: fclean bonus

# Check code style
norm:
	@norminette -R CheckForbiddenSourceHeader $(FILES);
	@norminette -R CheckDefine $(FILES);

# Phony targets
.PHONY: clean all fclean re norm bonus rebonus
