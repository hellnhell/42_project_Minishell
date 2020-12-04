/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_orders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:52:11 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/04 20:21:32 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_orders(t_tab *t, List *list, int i)
{
	while (t->orders[i])
	{
		save2_std(t);
		list = new_list();
		create_list_elemnts(t, list, i);
		t->iterator = list->first;
		t->i = 0;
		commands_redi_pipes(t, list);
		i++;
		reset_std23(t);
		ft_free_lists(list);
		free(t->index);
	}
	free_matrix(t->orders);
}
