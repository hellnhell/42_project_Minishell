/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:44:16 by hellnhell         #+#    #+#             */
/*   Updated: 2020/12/07 21:21:28 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "\e[91mM\e[92mI\e[93mN\e[94mI\e[95mS\e[96mH\e[91mE\e[92mL\e[93mL\e[94m% \e[0m "
# define READ_END    0
# define WRITE_END   1

# include	"../libft/libft.h"
# include	"../libft/get_next_line/get_next_line.h"
# include	"../printf/ft_printf.h"
# include	<stdio.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdlib.h>
# include	<errno.h>
# include 	<sys/types.h>
# include 	<sys/wait.h>
# include	<fcntl.h>
# include 	<signal.h>

typedef	struct 		s_counts
{
	int				y;
	int				x;
	unsigned int	j;
	int				i;
}					t_counts;

typedef	struct 		s_counts2
{
	int				a;
	int				b;
	int				i;
}					t_counts2;

char	*read_line(t_tab *t);
void	read_path(t_tab *t);
int		check_path(t_tab *t);
void	*ft_realloc(void *ptr, size_t originalsize, size_t newsize);
char	*ft_strtok(char *str, char *sepa);
char	*ft_strjoin_sl(const char *s1, const char *s2);
char	*ft_strjoin_sl2(const char *s1, const char *s2);
int		ft_echo(char **args);
int		ft_pwd(void);
int		ft_cd(char **args, char **env);
int		ft_export(char **args, t_tab *t);
int		ft_env(char **str);
int		ft_unset(char **args, t_tab *t);
int		ft_exit(char **args, t_tab *t);
int		check_our_implement(t_tab *t);
void	simbols_flags(t_tab *t, list *lst, int doubl);
void	free_matrix(char **matrix);
void	create_list_elemnts(t_tab *t, list *lst, int i);
void	check_builtins(t_tab *t);
void	check_bash_implement(t_tab *t);
void	commands_redi_pipes(t_tab *t, list *lst);
void	create_orders(t_tab *t, list *lst, int i);
int		check_quotes(char *s);
void	ft_minishell(t_tab *t, list *list);

void	ft_allocate_env(char **env, t_tab *t);
void	ft_cpy_env(char **env, t_tab *t);
void	ft_allocate_path(t_tab *t, char **path);
void	ft_cpy_path(t_tab *t, char **path);
void	ft_cpy_newenv(char **env, char **newenv, char *var, char *val);
char	**ft_realloc_env(t_tab *t, char *var, char *val, int k);


void	ft_pipes(t_tab *t);
void	save2_std(t_tab *t);
void	reset_std23(t_tab *t);
void	reset_stdout(t_tab *t);

void	ft_redi_greater(t_tab *t, node *iterator);
void	ft_redi_less(t_tab *t, node *iterator);
void	ft_redi_double(t_tab *t, node *iterator);
void	ft_redi_pipe(t_tab *t, node *iterator);
void	ft_redi_redi(t_tab *t, node *iterator, char c);

void	ft_signal_c(int sign);
void	ft_signal_c1(int sign);
void	ft_signal_d(int sign);
void	ft_signal_quit(int sign);

void	error_unex(t_tab *t);
void	not_command_error(t_tab *t);
void	err_nodir_pipe(char **str);
int		err_change_env(char *var, char *val, char *str, t_tab *t);

#endif
