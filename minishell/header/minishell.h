/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:20:57 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/08 15:34:51 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

typedef struct s_list
{
	char			*name;
	char			*content;
	bool			flag_export;
	bool			flag_env;
	struct s_list	*next;
}	t_list;

typedef struct s_lexer
{
	char			**wrd;
	char			**red;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_data
{
	t_list	*env;
	t_lexer	*lexer;
	char	**env_matrix;
	char	*prompt;
	char	*history;
	char	*pwd;
	int		history_fd;
	int		exit_status;
	int		infile_fd;
	int		outfile_fd;
	int		stdin_copy;
	int		stdout_copy;
}	t_data;

t_data	*ft_init_data(char **envp);
t_data	*ft_init_history(t_data *data);

t_list	*ft_get_env(char **envp);
t_list	*ft_init_nodino(char *content, bool flag_env, bool flag_export);
t_list	*ft_last_node_env(t_list *head);
t_list	*ft_free_list(t_list *node);

t_lexer	*ft_free_lexer(t_data *data);
t_lexer	*ft_add_front_lexer(t_lexer **head);
t_lexer	*ft_init_lexer(void);

void	ft_add_back_env(t_list **head, t_list *new);
void	ft_ac_error(void);
void	ft_miniputstr_fd(char *s, int fd);
void	ft_which_redirect(t_data *data, int fd_in, int fd_out);
void	ft_close_redirect(t_data *data);
void	ft_red_input(char *file, t_data *data);
void	ft_red_output(char *file, t_data *data, int append_or_not);
void	ft_sig_handler(int sig);
void	ft_sig_handler_cmd(int sig);
void	ft_ctrld_handler(t_data *data);
void	ft_ctrld_handler_heredoc(char *delimiter, int line_count);
void	ft_expand_wrd_red(t_data *data, char *which);

int		ft_free_data(t_data *data);
int		ft_choose_exec(t_data *data);
int		ft_setvariable(t_list **env, char *var, bool flag_env, bool flag_export);
int		ft_lexer(t_data *data);
int		ft_parser(t_data *data);
int		ft_fill_nodes(char *prompt, t_lexer *tmp);
int		ft_cd(t_data *data);
int		ft_getvaluelen(char *s);
int		ft_varexist(t_list *env, char *var);
int		ft_strlen_offset(char *str, char c);
int		ft_wrd_count(char *prompt);
int		ft_red_len(char *prompt);
int		ft_red_count(char *prompt);
int		ft_wrd_len(char *prompt);
int		ft_print_env(t_list *env);
int		ft_print_export(t_list *env);
int		ft_echo(char **wrd);
int		ft_cd_error(int len, char *home);
int		ft_unset(char **vars, t_list **env);
int		ft_export(char **vars, t_list **env);
int		ft_exit(t_data *data, char **wrd);
int		ft_error_quotes(void);
int		ft_jump_queck(char *prompt, char quote);
int		ft_pipe_syntax_error(char c);
int		ft_choose_exec(t_data *data);
int		ft_exec_no_pipe(t_data *data, t_lexer *node, int fd_in, int fd_out);
int		ft_redirect_handler(t_data *data, t_lexer *node);
int		ft_heredoc(char *delimiter, t_data *data);
int		ft_exec(t_data *data, char **wrd);
int		ft_isdirectory(char *dir_name);
int		ft_execve(char *cmd_path, char **cmd_args, t_data *data);
int		ft_exec_pipe(t_data *data, t_lexer *node, int fd_out);
int		ft_red_syntax_error(char *s);
int		ft_find_end_quote(char *prompt, int *flag, char quote);
int		ft_decide_len(char *prompt, char *chars_to_decide);
int		ft_print_exit_error(char *str);

char	*ft_getvarcontent(char *s, int content_len);
char	*ft_getvarname(char *s, int name_len);
char	*ft_fill_wrd(char *prompt);
char	*ft_clean_red(char *prompt);
char	*ft_expand_variable(char *str, t_data *data);
char	*ft_modify_result(char *old_result, char *var);
char	*ft_insert_non_variable(char *old_result, char *original, int *i);
char	*ft_skip(char *old_result, char *before_quotes);
char	*ft_skip_quotes(char *original);
char	*ft_expand_if_valid(char *original, t_data *data);
char	*ft_return_free(char *to_ret, char *to_free);

char	**ft_list_to_matrix(t_list *list);

bool	ft_isvariable(char *str);
bool	ft_isidentifier(char *str, bool msg);
bool	ft_all_spaces(char *str);
bool	ft_expansion_needed(char *str);

#endif
