/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/11/13 18:47:02 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	*read_line(t_tab *t)
{
	char	*line;

	// Aqui el line no hace nada?
	line = NULL;
	get_next_line(0, &t->line);
	return(t->line);
}

void	initt(t_tab *t)
{
	t->line = NULL;
	t->path = NULL;
	t->i = 0;
}

int		main(int argc, char **argv, char **env)
{
	t_tab	*t;
	int		i;
	int		j;
	List	*list;
	
	if(!(t = malloc (sizeof(t_tab))))
		return (1);
	initt(t);
	ft_allocate_env(env, t);
	ft_cpy_env(env, t);
			//execve("/bin/ls", env, env);
	
	(void)argc;
	(void)argv;
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
		 	Node *iterator = list->first;
			while (iterator != NULL)
			{
				t->tokens = ft_split_list(iterator->element, ' ', t);
				//printf("index--- %c\n i----- %i\n", t->index[t->i], t->i);
				if(t->index[t->i] && t->index[t->i] == '|' && !t->index[t->i - 1])
					ft_pipes_first(t, env);
				else if(t->index[t->i] && t->index[t->i] == '|' && t->index[t->i - 1] == '|')
					ft_pipes_mid(t, env);
				else if(!t->index[t->i] && t->index[t->i - 1] == '|')
					ft_pipes_end(t, env);
				//printf("list----%s\n", iterator->element);
				else
				{
					if(check_our_implement(t))
					{
						read_path(t, env);
						check_path(t, env);
					}
				}
				iterator = iterator->next;
				free(t->tokens); // Liberarlo bien
				t->i++;
			}
			i++;
			//system("leaks minishell");
			//t->tokens[i] = NULL;
		}
		free(t->orders);
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