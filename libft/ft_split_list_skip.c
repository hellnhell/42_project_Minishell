/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:25:21 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/02 18:26:04 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_skipdoubles(t_ints *a, char const *s, char c)
{
	while (s[a->i] == '\"')
	{
		a->i++;
		while (s[a->i] && s[a->i] != '\"')
			a->i++;
		a->i++;
		if (s[a->i] == c)
			a->counter++;
	}
}

void	ft_skipsimples(t_ints *a, char const *s, char c)
{
	while (s[a->i] == '\'')
	{
		a->i++;
		while (s[a->i] && s[a->i] != '\'')
			a->i++;
		a->i++;
		if (s[a->i] == c)
			a->counter++;
	}
}

void	ft_skip_all(t_ints *a, char const *s, char c)
{
	while (s[a->i] && s[a->i] != c)
	{
		a->i++;
		if (s[a->i] && s[a->i] == '\"')
		{
			a->i++;
			while (s[a->i] && s[a->i] != '\"')
				a->i++;
		}
		if (s[a->i] && s[a->i] == '\'')
		{
			a->i++;
			while (s[a->i] && s[a->i] != '\'')
				a->i++;
		}
	}
}
