/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:44:29 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/07 21:07:51 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_destroy_node(node *noode)
{
	free(noode->element);
	free(noode);
}

static void		ft_remove_back(list *lst)
{
	node		*pop;
	node		*prev_position;

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

void			ft_free_lists(list *lst)
{
	while (lst->first != NULL)
		ft_remove_back(lst);
	free(lst);
}
