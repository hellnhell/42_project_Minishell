/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/11/25 20:00:25 by emartin-         ###   ########.fr       */
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
		{
			ft_pipes(t, env);
			printf("un pipe\n");	
		}
		else if(t->index[t->i] && t->index[t->i] == '<' && t->index[t->i + 1] && t->index[t->i + 1] == '|')
		{
			iterator = iterator->next;
			ft_redi_pipe(t, env, iterator);

			/*free_matrix(t->tokens);
			iterator = iterator->next;
			t->tokens = ft_split_list(iterator->element, ' ', t);
			check_builtins(t, env);*/
			t->i++;
		}
		else if(t->index[t->i] && t->index[t->i] == '<' && t->index[t->i + 1] && (t->index[t->i + 1] == '>' || t->index[t->i + 1] == '-'))
		{
			iterator = iterator->next;
			ft_redi_redi(t, env, iterator, t->index[t->i + 1]);
			iterator = iterator->next;
		}
		else if(t->index[t->i] && t->index[t->i] == '>')
		{
			iterator = iterator->next;
			ft_redi_greater(t, env, iterator);
		}
		else if(t->index[t->i] && t->index[t->i] == '<')
		{
			iterator = iterator->next;
			ft_redi_less(t, env, iterator);			
		}
		else if(t->index[t->i] && t->index[t->i] == '-')
		{
			iterator = iterator->next;			
			ft_redi_double(t, env, iterator);
		}
		else 
			check_builtins(t, env);
		free_matrix(t->tokens);
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
		//system("leaks minishell");
		ft_putstr_fd(PROMPT, 1);
		signal(SIGINT, ft_signal_c);
		signal(SIGQUIT, ft_signal_c);
		t->line = read_line(t);
		//system("leaks minishell");
		t->orders = ft_split(t->line, ';');
		free(t->line);
		while (t->orders[i])
		{
			//system("leaks minishell");
			save_std(t);
			list = new_list();
			create_list_elemnts(t, list, i);
			iterate_list(t, list, env);
			i++;
			//system("leaks minishell");
			reset_std(t);
			ft_free_lists(list);
			free(t->index);
		}
		free_matrix(t->orders);
	}
}

void		free_matrix(char **matrix)
{
    int i;

    i = 0;
    while (matrix[i])
        i++;
    i--;
    while (i >= 0)
        free(matrix[i--]);
    free(matrix);
}
