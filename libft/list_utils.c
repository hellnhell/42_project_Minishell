/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:44:29 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/02 19:47:38 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_destroy_node(Node *node)
{
	free(node->element);
	free(node);
}

static void		ft_remove_back(List *list)
{
	Node		*pop;
	Node		*prev_position;

	pop = list->first;
	prev_position = NULL;
	if (list->first != NULL)
	{
		if (list->size > 1)
		{
			while (pop->next != NULL)
			{
				prev_position = pop;
				pop = pop->next;
			}
			prev_position->next = NULL;
		}
		else
			list->first = NULL;
		ft_destroy_node(pop);
		list->size--;
	}
}

void			ft_free_lists(List *list)
{
	while (list->first != NULL)
		ft_remove_back(list);
	free(list);
}
