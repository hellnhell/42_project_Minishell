/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lelemnts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:50:43 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/22 19:49:21 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_list_elemnts(t_tab *t, List *list, int i)
{
	int		j;
	int 	y;
	char	*aux;

	j = 0;
	y = 0;
	if (!(aux = malloc(sizeof(char*) * ft_strlen(t->orders[i]))))
		return;
	while (t->orders[i][j])
	{
		//if (t->orders[i][j] == ' ')
		//	j++;
		if (t->orders[i][j] != '|')
		{
			aux[y] = t->orders[i][j];
			//printf("car----%c\n", aux[y]);
			y++;
		}
		else
		{
			//printf("lo q deberia entrar en element----%s\n", aux);
			push_back(list, aux);
			list->first->pipe_b = 1;
			free(aux);
			y = 0;
		}
		j++;
		/*j++;
		x = 0;
		if (list->first != NULL)
		{
			while (t->orders[i][j])
			{
				t->orders[i][j] = args[x];
				j++;
				x++;
			}
			push_back(list, args);
			t->args[z] = args;
		}	*/

	}
}