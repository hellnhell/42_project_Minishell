/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:44:16 by hellnhell         #+#    #+#             */
/*   Updated: 2020/11/18 19:45:41 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "\e[91mM \e[92mA \e[93mR \e[94mI \e[95mS \e[96mH \e[91mE \e[92mL \e[93mL \e[94m% \e[0m "
# define READ_END    0    
# define WRITE_END   1

# include	"../libft/libft.h"
# include	"../libft/get_next_line/get_next_line.h"
# include	<stdio.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdlib.h>
# include	<errno.h>
# include 	<sys/types.h>
# include 	<sys/wait.h>
# include	<fcntl.h>
# include 	<signal.h>

char	*read_line(t_tab *t);
void	read_path(t_tab *t, char **env);
int		check_path(t_tab *t, char **env);
void 	*ft_realloc(void *ptr, size_t originalsize, size_t newsize);
char	*ft_strtok(char *str, char *sepa);
char	*ft_strjoin_sl(const char *s1, const char *s2);
char	*ft_strjoin_sl2(const char *s1, const char *s2);
int		ft_echo(char **args);
int		ft_pwd(void);
int		ft_cd(char **args, char **env);
int     ft_export(char **args, t_tab *t);
int     ft_env(char **env);
int		ft_unset(char **args, t_tab *t);
int		ft_exit(char **args, t_tab *t);
int		check_our_implement(t_tab *t);
char	**ft_split_com(char const *s, char c, t_tab *t);
void	simbols_flags(t_tab *t, List *list, int doubl);
void	free_matrix(char **matrix);
void	create_list_elemnts(t_tab *t,List *list,int i);
void	check_builtins(t_tab *t, char **env);









 
#define PROMPT "\e[91mM \e[92mA \e[93mR \e[94mI \e[95mS \e[96mH \e[91mE \e[92mL \e[93mL \e[94m% \e[0m "

void	ft_allocate_env(char **env, t_tab *t);
void	ft_cpy_env(char **env, t_tab *t);
void	ft_allocate_path(t_tab *t, char **path);
void	ft_cpy_path(t_tab *t, char **path);

void	ft_pipes_first(t_tab *, char **env);
void	ft_pipes_mid(t_tab *t, char **env);
void	ft_pipes_end(t_tab *t, char **env);
void	save_std(t_tab *t);
void	reset_std(t_tab *t);

void	ft_redi_greater(t_tab *t, char **env, Node *iterator);
void	ft_redi_less(t_tab *t, char **env, Node *iterator);
void	ft_redi_double(t_tab *t, char **env, Node *iterator);



#endif
