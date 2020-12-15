/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:32:26 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/08 17:40:55 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		pop_front(t_lista *lst)
{
	t_node	*pop;

	pop = lst->first;
	if (lst->first != NULL)
	{
		lst->first = lst->first->next;
		destructor_node(pop);
		lst->size--;
	}
}

void		pop_back(t_lista *lst)
{
	t_node	*pop;
	t_node	*previous_position;

	pop = lst->first;
	previous_position = NULL;
	if (lst->first != NULL)
	{
		if (lst->size > 1)
		{
			while (pop->next != NULL)
			{
				previous_position = pop;
				pop = pop->next;
			}
			previous_position->next = NULL;
			destructor_node(pop);
			lst->size--;
		}
		else
		{
			lst->first = NULL;
			destructor_node(pop);
			lst->size--;
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

t_lista		*copy_list(t_lista *lst)
{
	t_lista	*copy;
	t_node	*iterator;

	copy = new_list();
	iterator = lst->first;
	while (iterator != NULL)
	{
		push_back(copy, iterator->element);
		iterator = iterator->next;
	}
	return (copy);
}
