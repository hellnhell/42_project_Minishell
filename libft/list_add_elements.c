/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:15:23 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/02 19:26:11 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		push_front(List *list, char *s)
{
	Node		*new;

	new = new_node(s);
	new->next = list->first;
	list->first = new;
	list->size++;
}

void		push_back(List *list, char *s)
{
	Node	*new;
	Node	*iterator;

	new = new_node(s);
	iterator = NULL;
	if (list->first == NULL)
		list->first = new;
	else
	{
		iterator = list->first;
		while (iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = new;
	}
	list->size++;
}

void		push_after_n(List *list, char *s, int n)
{
	Node	*new;
	Node	*iterator;
	int		i;

	new = new_node(s);
	iterator = NULL;
	if (list->first == NULL)
		list->first = new;
	else
	{
		iterator = list->first;
		i = 0;
		while (iterator->next != NULL && i < n)
		{
			iterator = iterator->next;
			i++;
		}
		new->next = iterator->next;
		iterator->next = new;
	}
	list->size++;
}

char		*get_element(List *list, int n)
{
	Node	*iterator;
	int		i;

	iterator = NULL;
	if (list->first == NULL)
		return (NULL);
	else
	{
		i = 0;
		iterator = list->first;
		while (iterator->next != NULL && i < n)
		{
			iterator = iterator->next;
			i++;
		}
		if (i != n)
			return (NULL);
		else
			return (iterator->element);
	}
}
