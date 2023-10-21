# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 12:09:22 by cscelfo           #+#    #+#              #
#    Updated: 2023/09/06 11:52:39 by cscelfo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

LIB = $(NAME).a

ARCL = ar -crs

CC = cc

DEBUG_FLAG = -g

CFLAGS = -Wall -Wextra -Werror $(DEBUG_FLAG)

SRCS_DIR = srcs

OBJ_DIR = obj

LIB_DIR = lib

RMDIR = rm -rf

INCLUDE = header

MEM_DIR = mem

IS_SMTH_DIR = is_smth

STR_DIR = str

TO_SMTH_DIR = to_smth

PUT_DIR = put

LST_DIR = list

GNL_DIR = gnl

MAT_DIR = mat

PRINT_DIR = print

PRINT_FD_DIR = print_fd

ARR_DIR = arr

MEM_FILES =	ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_malloc.c \
			ft_calloc.c ft_memcmp.c ft_free.c ft_realloc.c \

IS_SMTH_FILES = ft_isalpha.c ft_isalnum.c ft_isprint.c ft_isascii.c ft_isdigit.c \
				ft_isspace.c \

STR_FILES =	ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strlen.c ft_strdup.c \
			ft_strnstr.c ft_strncmp.c ft_strjoin.c ft_substr.c ft_strtrim.c ft_strmapi.c \
			ft_striteri.c ft_strcmp.c ft_substr_skip.c ft_substr_skip_multiple.c\

TO_SMTH_FILES = ft_tolower.c ft_toupper.c ft_atoi.c ft_itoa.c ft_atof.c ft_atol.c ft_stack_to_arr.c \

PUT_FILES =	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

LST_FILES =	ft_init_node.c ft_last_node.c ft_add_node_before.c ft_add_node_after.c ft_smallest_node.c \
			ft_biggest_node.c \

GNL_FILES = ft_get_next_line.c \

MAT_FILES =	ft_split.c ft_matlen.c \

PRINT_FILES =	ft_print_char.c ft_print_str.c ft_print_nbr.c ft_print_u_nbr.c ft_print_hex.c \
				ft_print_ptr.c ft_printf.c \

PRINT_FD_FILES = ft_print_char_fd.c ft_print_str_fd.c ft_print_nbr_fd.c ft_print_u_nbr_fd.c ft_print_hex_fd.c \
				 ft_print_ptr_fd.c ft_printf_fd.c \

ARR_FILES =	ft_arrcpy.c

MEM_SRCS = $(addprefix $(MEM_DIR)/, $(MEM_FILES))

IS_SMTH_SRCS = $(addprefix $(IS_SMTH_DIR)/, $(IS_SMTH_FILES))

STR_SRCS = $(addprefix $(STR_DIR)/, $(STR_FILES))

TO_SMTH_SRCS = $(addprefix $(TO_SMTH_DIR)/, $(TO_SMTH_FILES))

PUT_SRCS = $(addprefix $(PUT_DIR)/, $(PUT_FILES))

LST_SRCS = $(addprefix $(LST_DIR)/, $(LST_FILES))

GNL_SRCS = $(addprefix $(GNL_DIR)/, $(GNL_FILES))

MAT_SRCS = $(addprefix $(MAT_DIR)/, $(MAT_FILES))

PRINT_SRCS = $(addprefix $(PRINT_DIR)/, $(PRINT_FILES))

PRINT_FD_SRCS = $(addprefix $(PRINT_FD_DIR)/, $(PRINT_FD_FILES))

ARR_SRCS = $(addprefix $(ARR_DIR)/, $(ARR_FILES))

SRCS_FILES =	$(MEM_SRCS) $(IS_SMTH_SRCS) $(STR_SRCS) $(TO_SMTH_SRCS) $(PUT_SRCS) \
				$(LST_SRCS) $(GNL_SRCS) $(MAT_SRCS) $(PRINT_SRCS) $(PRINT_FD_SRCS) $(ARR_SRCS) \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

O_SRCS = $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c $(INCLUDE)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

all: $(NAME)

$(NAME): $(SRCS) $(O_SRCS)
	$(ARCL) $(LIB) $(O_SRCS)
	mkdir -p $(LIB_DIR)
	mv -u $(LIB) $(LIB_DIR)

clean:
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(RMDIR) $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
