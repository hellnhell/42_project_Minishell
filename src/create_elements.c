/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:50:43 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/07 21:15:53 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			make_pop(list *lst, char *aux)
{
	if (ft_strlen(aux))
		push_back(lst, aux);
}

void			save_index(t_tab *t, int i, t_counts *count)
{
	if (t->orders[i][count->j] == '>' && t->orders[i][count->j + 1] == '>')
	{
		t->index[count->y] = '-';
		count->j++;
		count->y++;
	}
	else
	{
		t->index[count->y] = t->orders[i][count->j];
		count->y++;
	}
}

int				simbols(t_tab *t, t_counts *count)
{
	int			simbol;

	if ((t->orders[count->i][count->j] == '|') ||
		(t->orders[count->i][count->j] == '<')
		|| (t->orders[count->i][count->j] == '>'))
		simbol = 1;
	else
		simbol = 0;
	return (simbol);
}

void			ft_cle_2(t_tab *t, t_counts *count, char *aux, list *lst)
{
	while (t->orders[count->i][count->j])
	{
		if (!simbols(t, count))
		{
			aux[count->x] = t->orders[count->i][count->j];
			count->x++;
		}
		else
		{
			save_index(t, count->i, count);
			aux[count->x] = '\0';
			make_pop(lst, aux);
			count->x = 0;
		}
		count->j++;
	}
}

void			create_list_elemnts(t_tab *t, list *lst, int i)
{
	t_counts	*count;
	char		*aux;

	if (!(count = malloc(sizeof(t_counts))))
		return ;
	count->j = 0;
	count->y = 0;
	count->x = 0;
	count->i = i;
	if (!(t->index = malloc(sizeof(char *) * ft_strlen(t->orders[i]))))
		return ;
	if (!(aux = malloc(sizeof(char) * ft_strlen(t->orders[i]) + 1)))
		return ;
	ft_cle_2(t, count, aux, lst);
	aux[count->x] = '\0';
	make_pop(lst, aux);
	free(aux);
	free(count);
}
