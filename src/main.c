/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/10/22 20:03:13 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	ft_simbols(t_tab *t, int i , int j, List *list)
{
	if (t->orders[i][j] == '|')
		list->pipe_dch = 1;
}*/

char	*read_line(t_tab *t)
{
	char	*line;

	line = NULL;
	get_next_line(0, &t->line);
	return(t->line);
}

void	initt(t_tab *t, List *list)
{
	t->line = NULL;
	t->path = NULL;
	/*list->first->pipe_b = 0;
	list->first->pipe_a = 0;
	list->first->concat_a = 0;
	list->first->concat_b = 0;
	list->first->replace_a = 0;
	list->first->replace_b = 0;
	list->first->mins_a = 0;
	list->first->mins_b = 0;*/
}

int		main(int argc, char **argv, char **env)
{
	t_tab	*t;
	int		i;
	int		j;
	List	*list;
	
	if(!(t = malloc (sizeof(t_tab))))
		return (1);
	list = new_list();
	initt(t, list);
	(void)argc;
	(void)argv;
	(void)env;
	while (1)
	{
		i = 0;
		write(1, "marishell% ", 12);
		t->line = read_line(t);
		t->orders = ft_split(t->line, ';');
		while (t->orders[i])
		{
			create_list_elemnts(t, list, i);
		 	Node *iterator = list->first;
			while (iterator != NULL)
			{
				printf("list----%s\n", iterator->element);
				iterator = iterator->next;
			}
			printf("\n");
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
