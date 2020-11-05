/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:50:43 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/05 21:58:41 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		simbols(t_tab *t, int j, int i, int y)
{
	int		simbol;

	if (t->orders[i][j] == '>' && t->orders[i][j + 1] == '>')
	{
		t->index[y++] = '-';
	}
	if ((t->orders[i][j] == '|') || (t->orders[i][j] == '<') || (t->orders[i][j] == '>') ||
		(t->orders[i][j] == '-'))
		simbol = 1;
	else
		simbol = 0;
	return (simbol);	
}

static void 	save_simbols(t_tab *t, List *list, int i, int j) 
{
	int 	x;
	int		y;

	x = 0;
	y = 0;
	while (t->orders[i][j])
	{
		if (simbols(t, j, i, y) == 0) 
		{
			t->aux[x] = t->orders[i][j];
			x++;
		}
		else
		{
			t->index[y++] = t->orders[i][j];
			j++;
			t->aux[x] = '\0';
			push_back(list, t->aux);
			x = 0;
		}
		//simbols_flags(t, list, doubl);
		j++;
	}
}
/*void		simbols_flags(t_tab *t, List *list, int doubl)
{
	int		y;

	y = 0;
	Node *iterator = list->first;
	while (iterator != NULL)
	{
		while (t->index[y])
		{
			if (t->index[y] == '|')
			{
				list->first->pipe_a = 1;
				iterator->next->pipe_b = 1;
						
			}	
			else if (t->index[y] == '<')
			{
				list->first->mins_a = 1;
				iterator->next->mins_b = 1;
			}	
			else if (t->index[y] == '>')
			{
				list->first->concat_a= 1;
				iterator->next->concat_b = 1; 
			}
			else if (t->index[y] == '-')
			{
				list->first->replace_a = 1;
				iterator->next->replace_b = 1; 
			}
			y++;			
		}
		iterator = iterator->next;
	}
}*/


void	create_list_elemnts(t_tab *t, List *list, int i)
{
	unsigned int		j;
	int 				y;
	int					x;
	//char				*aux;

	j = 0;
	y = 0;
	x = 0;
	if (!(t->index = malloc(sizeof(char *) * ft_strlen(t->orders[i]))))
		return;
	
	if (!(t->aux = malloc(sizeof(char) * ft_strlen(t->orders[i]) + 1)))
		return;
	save_simbols(t, list, i, j);
	
	x = ft_strlen(t->aux);
	t->aux[x] = '\0';
	y = ft_strlen(t->index);
	printf("x---%d\ny----%d\n", x, y);
	t->index[y] = '\0';
	push_back(list, t->aux);
	free(t->aux);
	free(t->index);
}
