/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list_found.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:28:43 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/08 17:23:33 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			ft_dollar_count(char const *s, char **env)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	if (s[0] && s[0] == '?')
		return (2);
	while (env[i])
	{
		j = ft_strlen2(env[i]);
		if (!(n = ft_strncmp(s, env[i], j)) && (!s[j] ||
			(ft_isprint(s[j]) && !ft_isalnum(s[j]))))
		{
			n = ft_strlen(env[i] + j + 1) - j;
			return (n);
		}
		i++;
	}
	return (0);
}

void		ft_dollar_found(t_ints *a, char **env, char const *s)
{
	a->i = ft_dollar_count(&s[a->j + 1], env);
	a->counter += a->i;
	a->j++;
	if (a->i == 0)
	{
		while (s[a->j] && ft_isalnum(s[a->j]))
			a->j++;
		if (s[a->j + 1] && ft_isprint(s[a->j + 1]) && !ft_isalnum(s[a->j + 1]))
			a->j++;
		while (s[a->j] && ft_isprint(s[a->j]) && !ft_isalnum(s[a->j]))
			a->j++;
	}
}

void		ft_quotations_found(t_ints *a, char **env, char const *s)
{
	a->j++;
	while (s[a->j] && s[a->j] != '\"')
	{
		if (s[a->j] == '$')
		{
			a->i = ft_dollar_count(&s[a->j + 1], env);
			a->counter += a->i;
			a->j++;
			if (a->i == 0)
				while (s[a->j] && s[a->j] != ' ' && s[a->j] != '\"'
					&& s[a->j] != '\'' && s[a->j] != '$')
					a->j++;
		}
		else if (s[a->j] == '\\' && s[a->j + 1] && s[a->j + 1] == '\\')
			a->j++;
		else
		{
			a->j++;
			a->counter++;
		}
	}
	a->counter = a->counter - 1;
}

void		ft_simpquotations_found(t_ints *a, char const *s)
{
	a->j++;
	while (s[a->j] && s[a->j] != '\'')
	{
		a->j++;
		a->counter++;
	}
	a->counter = a->counter - 1;
}

void		ft_not_zero(t_ints *a)
{
	a->counter++;
	a->j++;
}
