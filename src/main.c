/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/11/04 13:39:38 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void		iterate_list(List *list, t_tab *t, int i, char **env)
{
	Node	*iterator;
	
	iterator = list->first;
	while (iterator != NULL)
	{
		printf("list----[%s]\n", iterator->element);
		t->tokens = ft_split_list(iterator->element, ' ', env);	//LEAK--- deberia liberarse en free matrix
		if(check_our_implement(t) == 1)
		{
			read_path(t, env);
			check_path(t, env);
		}
		iterator = iterator->next;
	}
	free_matrix(t->tokens);
	//printf("\n");
	i++;
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
}

int		main(int argc, char **argv, char **env)
{
	t_tab	*t;
	int		i;
	List	*list;

	
	if(!(t = malloc (sizeof(t_tab)))) //LEAK -still reachable
		return (1);
	initt(t);
	ft_allocate_env(env, t);
	//ft_cpy_env(env, t);
	(void)argc;
	(void)argv;
	while (1)
	{
		{
			i = 0;
			ft_putstr_fd(PROMPT, 1);
			t->line = read_line(t); //LEAK -still reachable
			t->orders = ft_split(t->line, ';'); //LEAK
			free (t->line);
			while (t->orders[i])
			{
				list = new_list();
				create_list_elemnts(t, list, i); //LEAK -still reachable --- liberar listas
				iterate_list(list, t, i, env); //LEAK -still reachable
				t->orders[i] = NULL;
				i++;
			}
			free_matrix(t->orders);
			//system("leaks minishell");
		}
	}
}
