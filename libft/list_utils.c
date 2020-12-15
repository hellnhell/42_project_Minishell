/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:44:29 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/08 17:41:24 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_destroy_node(t_node *noode)
{
	free(noode->element);
	free(noode);
}

static void		ft_remove_back(t_lista *lst)
{
	t_node		*pop;
	t_node		*prev_position;

	pop = lst->first;
	prev_position = NULL;
	if (lst->first != NULL)
	{
		if (lst->size > 1)
		{
			while (pop->next != NULL)
			{
				prev_position = pop;
				pop = pop->next;
			}
			prev_position->next = NULL;
		}
		else
			lst->first = NULL;
		ft_destroy_node(pop);
		lst->size--;
	}
}

void			ft_free_lists(t_lista *lst)
{
	while (lst->first != NULL)
		ft_remove_back(lst);
	free(lst);
}
