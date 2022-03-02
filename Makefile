# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:33:16 by spoolpra          #+#    #+#              #
#    Updated: 2022/03/02 23:50:36 by spoolpra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRC_DIR = srcs/
OBJ_DIR = objs/
LIB_DIR = libft/

INCS = -Iincludes/ -I$(LIB_DIR)includes/
NAME = push_swap
BONUS =
SRCS =
SRCS_BONUS =
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJS))
	@make -C $(LIB_DIR) --silent
	$(CC) $^ -o $(NAME) -L $(LIB_DIR) -lft
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< $(INCS) -o $@
bonus: $(addprefix $(OBJ_DIR),$(OBJS_BONUS))
	@make -C $(LIB_DIR) --silent
	$(CC) $^ -o $(BONUS) -L $(LIB_DIR) -lft
clean:
	@make -C $(LIB_DIR) clean --silent
	$(RM) $(OBJ_DIR)
fclean: clean
	@make -C $(LIB_DIR) fclean --silent
	$(RM) $(NAME)
	$(RM) checker
re: fclean all
