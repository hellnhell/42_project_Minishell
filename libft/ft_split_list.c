/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:53:01 by isfernan          #+#    #+#             */
/*   Updated: 2020/12/02 18:35:01 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** Esta función es otro split modificado, esta vez para tomar cada uno de los
** comandos y separarlo por espacios, manteniendo exactamente lo que hay dentro
** de las comillas y sustituyendo los $ por su valor solo si estamos dentro
** de las comillas dobles
*/

/*
** He cambiado esta función aquí pero en el otro split no!!!!
*/

static int	ft_countwords(char const *s, char c)
{
	t_ints	*a;
	int		n;

	a = malloc(sizeof(t_ints));
	a->counter = 0;
	a->i = 0;
	while (s[a->i])
	{
		ft_skipdoubles(a, s, c);
		ft_skipsimples(a, s, c);
		if (s[a->i] == c)
		{
			a->i++;
			continue ;
		}
		a->counter++;
		ft_skip_all(a, s, c);
	}
	n = a->counter;
	free(a);
	return (n);
}

static int	ft_size(char const *s, char c, int j, char **env)
{
	t_ints	*a;
	int		n;

	a = malloc(sizeof(t_ints));
	a->counter = 0;
	a->j = j;
	while (s[a->j] == c)
		a->j++;
	while (s[a->j] && s[a->j] != c)
	{
		a->i = 1;
		if (s[a->j] == '$')
			ft_dollar_found(a, env, s);
		if (s[a->j] == '\"')
			ft_quotations_found(a, env, s);
		if (s[a->j] == '\'')
			ft_simpquotations_found(a, s);
		if (a->i != 0)
			ft_not_zero(a);
	}
	n = a->counter + 1;
	free(a);
	return (n);
}

int			ft_check_dollar(char const *s, char **env)
{
	int		i;
	int		j;

	i = 0;
	if (s[0] && s[0] == '?')
		return (-1);
	while (env[i])
	{
		j = ft_strlen2(env[i]);
		if (!(ft_strncmp(s, env[i], j)) && (!s[j] ||
			(ft_isprint(s[j]) && !ft_isalnum(s[j]))))
			return (i + 1);
		i++;
	}
	return (0);
}

int			skip_env(char const *s)
{
	int		i;

	i = 0;
	while (s[i] && (ft_isalnum(s[i]) || s[i] == '?'))
		i++;
	return (i);
}

char		**ft_split_list(char const *s, char c, t_tab *t)
{
	int		i;
	int		j;
	int		words;
	char	**tab;

	j = 0;
	if (!s)
		return (NULL);
	i = ft_countwords(s, c);
	if (!(tab = malloc(sizeof(char **) * (i + 1))))
		return (NULL);
	tab[i] = NULL;
	words = i;
	i = 0;
	while (i < words)
	{
		tab[i] = malloc(sizeof(char) * ft_size(s, c, j, t->env));
		j = ft_cpyword(s, t, j, tab[i]);
		i++;
	}
	return (tab);
}
