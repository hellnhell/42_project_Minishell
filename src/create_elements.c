/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:50:43 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/02 21:18:58 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_pop(List *list, char *aux)
{
	if (ft_strlen(aux))
		push_back(list, aux);
}

int		simbols(t_tab *t, int j, int i)
{
	int		simbol;

	if ((t->orders[i][j] == '|') || (t->orders[i][j] == '<')
		|| (t->orders[i][j] == '>'))
		simbol = 1;
	else
		simbol = 0;
	return (simbol);
}

void	create_list_elemnts(t_tab *t, List *list, int i)
{
	unsigned int		j;
	int 				y;
	int					x;
	char				*aux;

	j = 0;
	y = 0;
	x = 0;
	if (!(t->index = malloc(sizeof(char *) * ft_strlen(t->orders[i]))))
		return ;
	if (!(aux = malloc(sizeof(char) * ft_strlen(t->orders[i]) + 1)))
		return ;
	while (t->orders[i][j])
	{
		if (simbols(t, j, i) == 0) 
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
			make_pop(list, aux);//CAMBIADO
			x = 0;
		}
		j++;
			//save_index(t, i, j); CAMBIADO
	}
	aux[x] = '\0';
	printf("%c\n", t->index[y]);
	make_pop(list, aux);//CAMBIADO
	free(aux);
}
