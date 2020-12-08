/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:45:20 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/08 17:42:31 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lista		*new_list(void)
{
	t_lista	*lst;

	if (!(lst = (t_lista *)malloc(sizeof(t_lista))))
		ft_putstr_fd("Malloc error lst\n", 1);
	lst->first = NULL;
	lst->size = 0;
	return (lst);
}

t_node		*new_node(char *s)
{
	t_node	*noode;

	noode = (t_node *)malloc(sizeof(t_node));
	noode->element = ft_strdup(s);
	noode->next = NULL;
	return (noode);
}

void		destructor_node(t_node *noode)
{
	free(noode->element);
	free(noode);
}

void		destructor_list(t_lista *lst)
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

int			size_list(t_lista *lst)
{
	return (lst->size);
}
