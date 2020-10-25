/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lelemnts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:50:43 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/25 19:52:23 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*char			*ft_strndup(const char *s, int c)
{
	int		pos;
	char	*dup;

	if (!(dup = malloc(ft_strlen(s) + 1)))
		return (NULL);
	pos = 0;
	while (s[pos] && pos <= c)
	{
		dup[pos] = s[pos];
		pos++;
	}
	dup[pos] = 0;
	return (dup);
}*/

/*int		simbols_flag(t_tab *t, List *list, int j, int i)
{
	if (t->orders[i][j] == '|')
	{
		printf("pipe\n");
		list->first->pipe = 1;
		return (1);
	}
	else if ((t->orders[i][j] == '<'))
	{
		printf("<\n");
		list->first->min = 1;
		return (1);
	}
	else if ((t->orders[i][j] == '>'))
	{
		printf(">\n");
		list->first->may = 1;
		return (1);
	}
	else if ((t->orders[i][j] == '>') && (t->orders[i][++j] == '>'))
	{
		printf(">>\n");
		list->first->doubmay = 1;
		return (1);
	}
	else
		return (0);	
}

void		simbols(t_tab *t, List *list, int y, int i)
{
	int 	j;

	j = 0;
	if (!(t->command = malloc(sizeof(char **) * ft_strlen(t->orders[i]))))
		return;
	while (j < ft_strlen(t->orders[i]))
	{
		if (list->first->pipe == 1 || list->first->may == 1 || 
		list->first->min == 1 || list->first->doubmay == 1 )
		{
			t->command[j] = ft_split(t->orders[i], );
			printf("command----%s\n", t->command[j]);
			j++;
		}
		j++;	
	}
}*/


void	create_list_elemnts(t_tab *t, List *list, int i)
{
	unsigned int		j;
	int 				y;
	unsigned int		len;
	char				*index;
	char				*aux;

	j = 0;
	y = 1;
	len = 0;
	if (!(aux = malloc(sizeof(char*) * ft_strlen(t->orders[i]))))
		return;
//	if (!(index = malloc(sizeof(int *) * ft_strlen(t->orders[i]))))
//		return;
	while (t->orders[i][j])
	{
		//guardar cada tipo de simbolo
		if (t->orders[i][j] == '|')
			j++;
		else
		{
			index[0] = '0';
			printf("index----%d\n", index[y]);
			index[y] = j;
			len = index[y] - index[y - 1];
			if (index[0] == 48)
			{
				aux = ft_substr(t->orders[i], 0, index[y]);
				push_back(list, aux);
			}
			else
			{
				aux = ft_substr(t->orders[i], index[y], len);
				push_back(list, aux);
				y++;
							
			}
			j++;
			//simbols(t, list, index, y, i);
		}
	}
	



	/*	if (list->first== NULL) 
		{
			/*
			push_back(list, aux);
			//printf("%d\n", index[y]);
			if (j > index[y])
			{
				aux = ft_substr(t->orders[i], j, ft_strlen(t->orders[i]));
				push_back(list, aux);	
			}
			y = 0;
			if (t->orders[i][j] != '|')
			{
				aux[y] = t->orders[i][j];
				y++;
			}
			else 
			{
				push_back(list, aux);
				list->first->pipe_b = 1;   //Esto es temporal hay q cambiarlo x simbols
				free(aux);
				y = 0;
			}
			j++;
		}
		else
		{
			printf("j---%i\n", j);
			printf("aux---%s\n", aux);
			while (t->orders[i][j])
			{
				aux[y] = t->orders[i][j];
				j++;
				y++;
			}
			push_back(list, aux);
		}
		
	}*/
}
