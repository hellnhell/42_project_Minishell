/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/11/17 19:32:04 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	iterate_list(t_tab *t, List *list, char **env)
{
	Node *iterator = list->first;
	while (iterator != NULL)
	{
		t->tokens = ft_split_list(iterator->element, ' ', t);
		if(t->index[t->i] && t->index[t->i] == '|' && !t->index[t->i - 1])
			ft_pipes_first(t, env);
		//check_pipes(t, env)		OLD CONTROL PIPES
		else 
			check_builtins(t, env);
		iterator = iterator->next;
		free(t->tokens); // Liberarlo bien
		t->i++;
	}
}

char	*read_line(t_tab *t)
{
	get_next_line(0, &t->line);
	return(t->line);
}

void	initt(t_tab *t)
{
	t->line = NULL;
	t->path = NULL;
	t->i = 0;
	t->status = 0;
}

int		main(int argc, char **argv, char **env)
{
	t_tab	*t;
	int		i;
	int		j;
	List	*list;
	
	(void)argc;
	(void)argv;
	if(!(t = malloc (sizeof(t_tab))))
		return (1);
	initt(t);
	ft_allocate_env(env, t);
	ft_cpy_env(env, t);
	while (1)
	{
		i = 0;
		//clear_terminal(env);
		ft_putstr_fd(PROMPT, 1);
		t->line = read_line(t);
		t->orders = ft_split(t->line, ';');
		while (t->orders[i])
		{
			list = new_list();
			create_list_elemnts(t, list, i);
			save_std(t);
			iterate_list(t, list, env);
			i++;
			//system("leaks minishell");
		}
		free(t->orders);
		clean_std(t);
	}
}

/*
void		free_matrix(char **matrix)
{
	int		i;
	
	i = 0;
	while(matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
*/