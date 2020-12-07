/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:15:23 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/07 20:58:47 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		push_front(list *lst, char *s)
{
	node		*new;

	new = new_node(s);
	new->next = lst->first;
	lst->first = new;
	lst->size++;
}

void		push_back(list *lst, char *s)
{
	node	*new;
	node	*iterator;

	new = new_node(s);
	iterator = NULL;
	if (lst->first == NULL)
		lst->first = new;
	else
	{
		iterator = lst->first;
		while (iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = new;
	}
	lst->size++;
}

void		push_after_n(list *lst, char *s, int n)
{
	node	*new;
	node	*iterator;
	int		i;

	new = new_node(s);
	iterator = NULL;
	if (lst->first == NULL)
		lst->first = new;
	else
	{
		iterator = lst->first;
		i = 0;
		while (iterator->next != NULL && i < n)
		{
			iterator = iterator->next;
			i++;
		}
		new->next = iterator->next;
		iterator->next = new;
	}
	lst->size++;
}

char		*get_element(list *lst, int n)
{
	node	*iterator;
	int		i;

	iterator = NULL;
	if (lst->first == NULL)
		return (NULL);
	else
	{
		i = 0;
		iterator = lst->first;
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
