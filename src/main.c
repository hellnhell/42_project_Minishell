/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/11/20 18:00:54 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	iterate_list(t_tab *t, List *list, char **env)
{
	Node *iterator = list->first;
	
	t->i = 0;
	while (iterator != NULL)
	{
		t->tokens = ft_split_list(iterator->element, ' ', t);
		if(t->index[t->i] && t->index[t->i] == '|')
			ft_pipes(t, env);
		else if(t->index[t->i] && t->index[t->i] == '>')
		{
			iterator = iterator->next;
			ft_redi_greater(t, env, iterator);
		}
		else if(t->index[t->i] && t->index[t->i] == '<')
		{
			ft_redi_less(t, env, iterator);			
			iterator = iterator->next;
		}
		else if(t->index[t->i] && t->index[t->i] == '-')
		{
			iterator = iterator->next;			
			ft_redi_double(t, env, iterator);
		}
		else 
			check_builtins(t, env);
		iterator = iterator->next;
		t->i++;
	}
}

char	*read_line(t_tab *t)
{
	if (!get_next_line(0, &t->line))
		ft_signal_d(1);
	return(t->line);
}

void	initt(t_tab *t)
{
	t->line = NULL;
	t->path = NULL;
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
		signal(SIGINT, ft_signal_c);
		signal(SIGQUIT, ft_signal_c);
		t->line = read_line(t);
		t->orders = ft_split(t->line, ';');
		while (t->orders[i])
		{
			save_std(t);
			list = new_list();
			create_list_elemnts(t, list, i);
			iterate_list(t, list, env);
			i++;
			//system("leaks minishell");
			reset_std(t);
			free_matrix(t->tokens);
		}
		free_matrix(t->orders);
	}
}

void		free_matrix(char **matrix)
{
	int		i;
	
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
