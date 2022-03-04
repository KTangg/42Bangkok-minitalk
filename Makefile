# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:33:16 by spoolpra          #+#    #+#              #
#    Updated: 2022/03/04 16:25:24 by spoolpra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRC_DIR = srcs/
OBJ_DIR = objs/
LIB_DIR = libft/

INCS = -Iincludes/ -I$(LIB_DIR)includes/
NAME = server client
SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(addprefix $(OBJ_DIR),$(OBJS))
	@make -C $(LIB_DIR) --silent
	$(CC) $(addprefix $(OBJ_DIR),client.o) -o client -L $(LIB_DIR) -lft
	$(CC) $(addprefix $(OBJ_DIR),server.o) -o server -L $(LIB_DIR) -lft
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< $(INCS) -o $@
bonus: $(NAME)
clean:
	@make -C $(LIB_DIR) clean --silent
	$(RM) $(OBJ_DIR)
fclean: clean
	@make -C $(LIB_DIR) fclean --silent
	$(RM) client
	$(RM) server
re: fclean all
