/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:50:43 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/10 17:22:23 by emartin-         ###   ########.fr       */
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
	char				*aux;
	int					doubl;

	j = 0;
	y = 0;
	doubl = 0;
	x = 0;
	if (!(t->index = malloc(sizeof(char *) * ft_strlen(t->orders[i]))))
		return ;
	if (!(aux = malloc(sizeof(char) * ft_strlen(t->orders[i]) + 1)))
		return ;
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
	//printf("index---%s\n", t->index);
	//printf("auxj: %s\n", &aux[j]);
	push_back(list, aux);
			//printf("aux----%s\n", aux);
	free(t->index);
}
/*static int		count_simbols(char *str)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;	
	while (str[i])
	{
		if (str[i] == '|' || str[i] == '<' || str[i] == '>')
		{
			j++;
			if (str[i + 1] && str[i] == '>')
				i++;
		}
		i++;		
	}
	return (j + 1);
}

static int		not_simbols(t_tab *t, int j, int i, int y)
{
	int		simbol;


	if ((t->orders[i][j] == '|') || (t->orders[i][j] == '<') || (t->orders[i][j] == '>'))
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
		if (not_simbols(t, j, i, y) == 0) 
			t->aux[x++] = t->orders[i][j];
		else
		{
			if (t->orders[i][j] == '>' && t->orders[i][j + 1] == '>')
			{
				t->index[y++] = '-';
				j = j + 1;
			}
			else
				t->index[y++] = t->orders[i][j];
			t->aux[x] = '\0';
			printf("aux----%s\n", t->aux);
			push_back(list, t->aux);
			x = 0;
		}
		//simbols_flags(t, list, doubl);
		j++;
	}
}

void	create_list_elemnts(t_tab *t, List *list, int i)
{
	unsigned int		j;
	int 				y;
	int					x;
	//char				*aux;

	j = 0;
	y = 0;
	x = 0;
	if (!(t->index = malloc(sizeof(char) * count_simbols(t->orders[i]))))
		return;
	
	if (!(t->aux = calloc(ft_strlen(t->orders[i]) + 1, 1)))
		return;
	save_simbols(t, list, i, j);
	printf("index------  %s\n", t->index);
	x = ft_strlen(t->aux);
	t->aux[x] = '\0';
	y = ft_strlen(t->index);
	t->index[y] = '\0';
	push_back(list, t->aux);
	free(t->aux);
	free(t->index);
}
*/