/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:32:26 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/02 19:38:59 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		pop_front(List *list)
{
	Node	*pop;

	pop = list->first;
	if (list->first != NULL)
	{
		list->first = list->first->next;
		destructor_node(pop);
		list->size--;
	}
}

void		pop_back(List *list)
{
	Node	*pop;
	Node	*previous_position;

	pop = list->first;
	previous_position = NULL;
	if (list->first != NULL)
	{
		if (list->size > 1)
		{
			while (pop->next != NULL)
			{
				previous_position = pop;
				pop = pop->next;
			}
			previous_position->next = NULL;
			destructor_node(pop);
			list->size--;
		}
		else
		{
			list->first = NULL;
			destructor_node(pop);
			list->size--;
		}
	}
}

int			compare_element_c(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

List		*copy_list(List *list)
{
	List	*copy;
	Node	*iterator;

	copy = new_list();
	iterator = list->first;
	while (iterator != NULL)
	{
		push_back(copy, iterator->element);
		iterator = iterator->next;
	}
	return (copy);
}
