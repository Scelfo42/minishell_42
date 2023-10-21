.SILENT:

MAKEFLAGS		+=	--silent

NAME 			:=	minishell

RM_DIR			:=	rm -rf

CC				:=	gcc

DEBUG_FLAG		:=	-g

READLINE_FLAG	:=	-lreadline

CFLAGS			:=	-Wall -Werror -Wextra $(DEBUG_FLAG)

LIBFT 			:=	libft

INCLUDE			:=	header

INCLUDE_2		:=	$(LIBFT)/$(INCLUDE)

DEPS			:=	$(INCLUDE)/ $(LIBFT)/$(INCLUDE)/

SRCS_DIR		:=	srcs

OBJ_DIR			:=	obj

LIBFT_SRCS		:=	$(LIBFT)/$(SRCS_DIR)

LIB_DIR			:=	$(LIBFT)/lib

LIB				:=	-lft

SRCS_FILES		:=	main.c							\
													\
					memory/free.c					\
													\
					errors/error.c					\
					errors/error2.c					\
													\
					shell_utils/history.c			\
					shell_utils/isdirectory.c		\
					shell_utils/list_to_matrix.c	\
					shell_utils/main_utils.c		\
													\
					init/init_data.c				\
					init/init_data_utils.c			\
					init/getenv_utils.c				\
					init/print_envs.c				\
													\
					parsing/parser.c				\
					parsing/parser_utils.c			\
					parsing/lexer.c					\
					parsing/lexer_utils.c			\
					parsing/expand_var.c			\
					parsing/expand_var_utils.c		\
					parsing/expand_var_utils2.c		\
													\
					builtins/echo.c					\
					builtins/cd.c					\
					builtins/setvariable.c			\
					builtins/export.c				\
					builtins/unset.c				\
					builtins/exit.c					\
													\
					executor/choose_exec.c			\
					executor/exec.c					\
					executor/execve.c				\
					executor/heredoc.c				\
					executor/redirects_utils.c		\
					executor/redirects.c

SCRS			:=	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

O_SRCS			:=	$(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

# COLORS ================================================================= #

RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
WHITE = \033[0;97m

# ======================================================================== #

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c $(DEPS)
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -I $(INCLUDE) -I $(INCLUDE_2) -c $< -o $@
			@echo "$(GREEN)Compiling:$(WHITE) $<"

all: $(NAME)

$(NAME): $(SRCS) $(O_SRCS)
	@$(MAKE) -C $(LIBFT) all
	@$(CC) $(CFLAGS) $(O_SRCS) -o $(NAME) -L $(LIB_DIR)/ $(LIB) $(READLINE_FLAG)
	@echo "$(YELLOW)- Program Name: $(WHITE)${NAME}"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}"

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(RM_DIR) $(OBJ_DIR)/
	@echo "$(RED)All $(CYAN)$(NAME)$(RED)'s objects removed with $(WHITE)${RM} $(YELLOW)"

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	@$(RM_DIR) $(NAME)
	@rm -f .minishell_history
	@rm -f .heredoc
	@echo "$(RED)..and $(CYAN)${NAME} $(RED)has been removed"

re: fclean all

.PHONY: all clean fclean re
