/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/10/20 21:32:23 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_simbols(t_tab *t, int i , int j, t_list *list1)
{
	if (t->orders[i][j] == '|')
		list1->pipe_dch = 1;
}

char	*read_line(t_tab *t)
{
	char	*line;

	line = NULL;
	get_next_line(0, &t->line);
	return(t->line);
}

void	initt(t_tab *t, t_list *list1)
{
	t->line = NULL;
	t->path = NULL;
	list1->pipe_dch = 0;
	list1->pipe_izq = 0;
	list1->concat_izq = 0;
	list1->concat_dch = 0;
	list1->replace_izq = 0;
	list1->replace_dch = 0;
	list1->mins_izq = 0;
	list1->mins_dch = 0;
}

int		main(int argc, char **argv, char **env)
{
	t_tab	*t;
	int		i;
	int		j;
	int 	z;
	t_list	*list1;
	void	*node2;
	t_list	*new;

	if (!(list1 = (t_list *) malloc(sizeof(t_list))))
		return (1);
	if(!(t = malloc (sizeof(t_tab))))
		return (1);
	initt(t, list1);
	(void)argc;
	(void)argv;
	(void)env;
	while (1)
	{
		i = 0;
		ft_putstr_fd("marishell% ", 1);
		t->line = read_line(t);
		t->orders = ft_split(t->line, ';');
		while (t->orders[i])
		{
			j = 0;
			while (t->orders[i][j])
			{
				if (t->orders[i][j] >= 'A' && t->orders[i][j] <= 'z')
				{
					list1->content = t->orders[i];
					ft_simbols(t, i, j, list1);
					j++;
					z = 0;
					while (t->orders[i][j])
					{
						t->after_simbol[z] = t->orders[i][j];
						j++;
					}	
					if (list1->next == NULL)
					{
						ft_lstadd_back(&list1, new);
						printf("h\n");
					}
					new->content = t->after_simbol;
				}	
			}
			t->tokens = ft_split_com(t->orders[i], ' ',t);
			if(check_our_implement(t))
			{
				read_path(t, env);
				check_path(t, env);
			}
			i++;
			free(t->tokens);
		}
		free(t->orders);
	}
}
