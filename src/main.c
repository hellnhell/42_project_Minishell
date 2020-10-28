/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/10/28 19:48:59 by isfernan         ###   ########.fr       */
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
	(void)argc;
	(void)argv;
	while (1)
	{
		i = 0;
		write(1, "marishell% ", 12);
		t->line = read_line(t);
		t->orders = ft_split(t->line, ';');
		while (t->orders[i])
		{
			list = new_list();
			create_list_elemnts(t, list, i);
		 	Node *iterator = list->first;
			while (iterator != NULL)
			{
				printf("list----%s\n", iterator->element);
				t->tokens = ft_split_list(iterator->element, ' ', env);
				if(check_our_implement(t, env))
				{
					read_path(t, env);
					check_path(t, env);
				}
				iterator = iterator->next;
				free(t->tokens);
			}
			printf("\n");
			i++;
			t->orders[i] = NULL;
		}
		free(t->orders);
	}
}
