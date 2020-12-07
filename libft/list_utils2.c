/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:45:20 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/07 21:08:22 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

list		*new_list(void)
{
	list	*lst;

	if (!(lst = (list *)malloc(sizeof(list))))
		ft_putstr_fd("Malloc error lst\n", 1);
	lst->first = NULL;
	lst->size = 0;
	return (lst);
}

node		*new_node(char *s)
{
	node	*noode;

	noode = (node *)malloc(sizeof(node));
	noode->element = ft_strdup(s);
	noode->next = NULL;
	return (noode);
}

void		destructor_node(node *noode)
{
	free(noode->element);
	free(noode);
}

void		destructor_list(list *lst)
{
	int		i;

	i = 0;
	while (lst->first != NULL)
	{
		pop_front(lst);
		i++;
	}
	free(lst);
}

int			size_list(list *lista)
{
	return (lista->size);
}
