/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:50:43 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/26 19:18:39 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		simbols(t_tab *t, List *list, int j, int i)
{
	int		simbol;

	if ((t->orders[i][j] == '|') || (t->orders[i][j] == '<') || (t->orders[i][j] == '>'))
		simbol = 1;
	else
		simbol = 0;
	return (simbol);	
}

void		simbols_flags(t_tab *t, List *list, int doubl)
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
}


void	create_list_elemnts(t_tab *t, List *list, int i)
{
	unsigned int		j;
	int 				y;
	int					x;
	char				*aux;
	int					doubl;

	j = 0;
	y = 0;
	doubl = 0;
	x = 0;
	if (!(t->index = malloc(sizeof(char *) * ft_strlen(t->orders[i]))))
		return;
	if (!(aux = malloc(sizeof(char) * ft_strlen(t->orders[i]) + 1)))
		return;
	while (t->orders[i][j])
	{
		if (simbols(t, list, j, i) == 0) 
		{
			aux[x] = t->orders[i][j];
			x++;
		}	
		else
		{
			if (t->orders[i][j] == '>' && t->orders[i][j + 1] == '>')
			{
				t->index[y] = '-';
				j++;
				y++;
			}
			else
			{
				t->index[y] = t->orders[i][j];
				y++;
			}
			aux[x] = '\0';
			push_back(list, aux);
			x = 0;
		}
		//simbols_flags(t, list, doubl);
		j++;
	}
	aux[x] = '\0';
	printf("index---%s\n", t->index);
	printf("auxj: %s\n", &aux[j]);
	push_back(list, aux);
			//printf("aux----%s\n", aux);
	free(t->index);
}
