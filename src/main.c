/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/11/02 21:25:53 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		iterate_list(List *list, t_tab *t, int i, char **env)
{
	Node	*iterator;
	
	iterator = list->first;
	while (iterator != NULL)
	{
		printf("list----[%s]\n", iterator->element);
		t->tokens = ft_split_list(iterator->element, ' ', env);				//GESTIONAR EL EXIT STATUS
		if(check_our_implement(t, env) == 1)
		{
			read_path(t, env);
			check_path(t, env);
		}
		iterator = iterator->next;
		free(t->tokens);
	}
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
	int		j;
	List	*list;
	//pid_t	pid_min;
	//int		status;
	
	if(!(t = malloc (sizeof(t_tab))))
		return (1);
	initt(t);
	ft_allocate_env(env, t);
	ft_cpy_env(env, t);
	(void)argc;
	(void)argv;
	while (1)
	{
		{
			i = 0;
			ft_putstr_fd(PROMPT, 1);
			t->line = read_line(t);
			t->orders = ft_split(t->line, ';');
			while (t->orders[i])
			{
				list = new_list();
				create_list_elemnts(t, list, i);
				iterate_list(list, t, i, env);
				//destructor_list(list);
				t->orders[i] = NULL;
			}
			free(t->orders);
		}
		//system("leaks minishell");
	}
	
}
