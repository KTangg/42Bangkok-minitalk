# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:33:16 by spoolpra          #+#    #+#              #
#    Updated: 2022/03/02 23:27:31 by spoolpra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libft.a
RM = rm -rf
SRC_DIR = srcs/
OBJ_DIR = objs/

IS_LIBC = ft_isalnum.c ft_isascii.c ft_isprint.c ft_isdigit.c ft_isalpha.c ft_isspace.c
TO_LIBC = ft_toupper.c ft_tolower.c ft_atoi.c
STR_LIBC = ft_strchr.c ft_strrchr.c ft_strlen.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strdup.c
MEM_LIBC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c
LIBC = $(IS_LIBC) $(TO_LIBC) $(STR_LIBC) $(MEM_LIBC)
STR_ADDC = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c
PUT_ADDC = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
LST_ADDC = ft_lstsize.c ft_lstnew.c ft_lstmap.c ft_lstlast.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c ft_lstaddback.c
PRINTF = ft_printf.c ft_printf_extend_format.c ft_printf_extend_format_util_1.c ft_printf_get_format.c ft_printf_get_format_util_1.c ft_printf_helper.c ft_printf_util_1.c ft_printf_util_2.c ft_printf_util_3.c ft_printf_util_4.c \
ft_printf_extend_format_util_2.c ft_printf_extend_format_util_3.c ft_printf_extend_format_util_4.c
GNL = ft_get_next_line.c ft_get_next_line_utils.c
ADDC = $(STR_ADDC) $(PUT_ADDC) $(PRINTF) $(GNL)
SRCS = $(LIBC) $(ADDC)
OBJS = $(SRCS:.c=.o)
INCS = -Iincludes/

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJS))
	ar -rcs $@ $^
	ranlib $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< $(INCS) -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
