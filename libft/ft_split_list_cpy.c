/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list_cpy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:32:52 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/02 19:09:29 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_dollar_cpy(t_ints *a, t_tab *t, char *str, char const *s) //TIENE 26 líneas
{
	int		n;
	int		z;
	char	*itoa;

	a->j++;
	n = ft_check_dollar(&s[a->j], t->env);
	if (n > 0)
	{
		z = ft_strlen2(t->env[n - 1]) + 1;
		while (t->env[n - 1][z])
			str[a->i++] = t->env[n - 1][z++];
		while (s[a->j] && (ft_isalnum(s[a->j])))
			a->j++;
	}
	else if (n == -1)
	{
		z = 0;
		itoa = ft_itoa(t->status);
		while (itoa[z])
			str[a->i++] = itoa[z++];
		free(itoa);
		a->j += skip_env(&s[a->j]);
	}
	else
		while (s[a->j] && (ft_isalnum(s[a->j])))
			a->j++;
}

/*
** en env[n - 1] le restamos uno porque hemos devuleto el índice +1
*/

void	ft_quotations_cpy(t_ints *a, t_tab *t, char *str, char const *s)
{
	int		n;
	int		z;

	a->j++;
	while (s[a->j] && s[a->j] != '\"')
	{
		if (s[a->j] == '$' && (n = ft_check_dollar(&s[a->j + 1], t->env)))
		{
			z = ft_strlen2(t->env[n - 1]) + 1;
			while (t->env[n - 1][z])
				str[a->i++] = t->env[n - 1][z++];
			a->j += skip_env(&s[a->j + 1]);
		}
		else if (s[a->j] == '$')
			a->j += skip_env(&s[a->j + 1]);
		else
			str[a->i++] = s[a->j];
		if (s[a->j] == '\\' && s[a->j + 1] && s[a->j + 1] == '\\')
			a->j++;
		a->j++;
	}
	a->j++;
}

void	ft_simpquotations_cpy(t_ints *a, char *str, char const *s)
{
	a->j++;
	while (s[a->j] && s[a->j] != '\'')
	{
		str[a->i++] = s[a->j++];
	}
	a->j++;
}

int		ft_cpyword(char const *s, t_tab *t, int j, char *str)
{
	t_ints	*a;
	char	c;
	int		n;

	a = malloc(sizeof(t_ints));
	a->i = 0;
	a->j = j;
	c = ' ';
	while (s[a->j] == c)
		a->j++;
	while (s[a->j] && s[a->j] != c)
	{
		if (s[a->j] == '$')
			ft_dollar_cpy(a, t, str, s);
		else if (s[a->j] == '\"')
			ft_quotations_cpy(a, t, str, s);
		else if (s[a->j] == '\'')
			ft_simpquotations_cpy(a, str, s);
		else if (s[a->j] && s[a->j] != c && s[a->j] != '$')
			str[a->i++] = s[a->j++];
	}
	str[a->i] = 0;
	n = a->j;
	free(a);
	return (n);
}
