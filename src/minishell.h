/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:44:16 by hellnhell         #+#    #+#             */
/*   Updated: 2020/11/10 19:16:21 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "\e[91mM \e[92mA \e[93mR \e[94mI \e[95mS \e[96mH \e[91mE \e[92mL \e[93mL \e[94m% \e[0m "


# include	"../libft/libft.h"
# include	"../libft/get_next_line/get_next_line.h"
# include	<stdio.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdlib.h>
# include	<errno.h>
# include 	<sys/types.h>
# include 	<signal.h>


typedef struct Node
{
    char    *element;
    struct Node *next;
} Node;

typedef struct  List {
    Node	*first;
	int 	size;
} List;


char	*read_line(t_tab *t);
void	read_path(t_tab *t, char **env);
int		check_path(t_tab *t, char **env);
char	**split_line(char *line);
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
int		ft_exit(char **args);
int		check_our_implement(t_tab *t, char **env);
char	**ft_split_com(char const *s, char c, t_tab *t);
void	simbols_flags(t_tab *t, List *list, int doubl);
int		simbols(t_tab *t, List *list, int j, int i);


List    *new_list(void);
Node    *new_node(char *s);
void    destructor_node(Node *node);
void    destructor_list(List *list);
void    pop_front(List *list);
void    pop_back(List *list);
void    pop_n_element(List *list, int n);
void    push_front(List *list, char *s);
void    push_back(List *list, char *s);
void    push_after_n(List *list, char *s, int n);
List    *copy_list(List *list);
void	create_list_elemnts(t_tab *t,List *list,int i);

void	ft_allocate_env(char **env, t_tab *t);
void	ft_cpy_env(char **env, t_tab *t);
void	ft_allocate_path(t_tab *t, char **path);
void	ft_cpy_path(t_tab *t, char **path);



#endif
