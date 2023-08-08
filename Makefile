# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 16:08:21 by whendrik          #+#    #+#              #
#    Updated: 2023/08/05 12:58:40 by whendrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FLAGS
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -g -o3
# S_FLAGS = -g -fsanitize=address,undefined

#commands
RM = rm -rf
AR = ar rc

#Targlib name and dirs
NAME = push_swap
LIBFT = libft/libft.a
SRC_DIR =src
SRC_FILES= main.c 

OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft
INCS = -I$(INC_DIR) -I$(LIBFT_DIR)

# Sources, objects and dependencies
SOURCES = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJECTS = $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)

# Default target, build the library
all: $(LIBFT_DIR) $(NAME)

# Rule to build each personal library
$(LIBFT):
	make -C $(LIBFT_DIR)

# Object file build rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) -c $< -o $@


$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(C_FLAGS) $^ $(INCS) -o $(NAME)

# Clean object files
clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

# Clean object files and target library
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_DIR)/libft.a
	make fclean -C $(LIBFT_DIR) 

re: fclean all

# Check code style
norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*.c ;
	@norminette -R CheckDefine $(INC_DIR)/*.h ;
	@norminette -R CheckForbiddenSourceHeader $(LIBFT_DIR)/src/*.c ;
	@norminette -R CheckDefine $(LIBFT_DIR)/includes/*.h

# Phony targets
.PHONY: clean all fclean re norm
