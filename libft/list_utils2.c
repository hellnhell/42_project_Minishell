/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:45:20 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/02 19:49:16 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

List		*new_list(void)
{
	List	*list;

	if (!(list = (List *)malloc(sizeof(List))))
		ft_putstr_fd("Malloc error list\n", 1);
	list->first = NULL;
	list->size = 0;
	return (list);
}

Node		*new_node(char *s)
{
	Node	*node;

	node = (Node *)malloc(sizeof(Node));
	node->element = ft_strdup(s);
	node->next = NULL;
	return (node);
}

void		destructor_node(Node *node)
{
	free(node->element);
	free(node);
}

void		destructor_list(List *list)
{
	int		i;

	i = 0;
	while (list->first != NULL)
	{
		pop_front(list);
		i++;
	}
	free(list);
}

int			size_list(List *lista)
{
	return (lista->size);
}
