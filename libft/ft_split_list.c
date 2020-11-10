/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:53:01 by isfernan          #+#    #+#             */
/*   Updated: 2020/11/10 18:00:27 by emartin-         ###   ########.fr       */
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

/*
** Esta función recibe una cadena cuyo primer caracter es el
** que va después de $ y devuelve el valor de la cadena de
** caracteres por la que vamos a tener que sustituir la
** variable de ambiente correspondiente
**
** env[i] + j + 1 -> el 1 es por el dólar
*/

int			ft_dollar_count(char const *s, char **env)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	if (s[0] == '?')
		return (3);
	while (env[i])
	{
		j = ft_strlen2(env[i]);
		if (!(n = ft_strncmp(s, env[i], j)) && (!s[j] || s[j] == ' ' ||
			s[j] == '\"' || s[j] == '\'' || s[j] == '$'))
		{
			n = ft_strlen(env[i] + j + 1) - j;
			return (n);
		}
		i++;
	}
	return (0);
}

void	ft_dollar_found(t_ints *a, char **env, char const *s)
{
	a->i = ft_dollar_count(&s[a->j + 1], env);
	a->counter += a->i;
	a->j++;
	if (a->i == 0)
		while (s[a->j] && s[a->j] != ' ' && s[a->j] != '\"' &&
			s[a->j] != '\'' && s[a->j] != '$')
			a->j++;
}

void	ft_quotations_found(t_ints *a, char **env, char const *s)
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
		else
		{
			a->j++;
			a->counter++;
		}
	}
	a->counter = a->counter - 1;
}

void	ft_simpquotations_found(t_ints *a, char const *s)
{
	a->j++;
	while (s[a->j] && s[a->j] != '\'')
	{
		a->j++;
		a->counter++;
	}
	a->counter = a->counter - 1;
}

void	ft_not_zero(t_ints *a)
{
	a->counter++;
	a->j++;
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

/*
** Devolvemos i + 1 porque la i puede ser 0 y no queremos devolver
** 0 si lo hemos encontrado
*/

int			ft_check_dollar(char const *s, char **env)
{
	int		i;
	int		j;

	i = 0;
	if (s[0] == '?')
		return (-1);
	while (env[i])
	{
		j = ft_strlen2(env[i]);
		if (!(ft_strncmp(s, env[i], j)) && (!s[j] || s[j] == ' ' ||
			s[j] == '\"' || s[j] == '\'' || s[j] == '$'))
			return (i + 1);
		i++;
	}
	return (0);
}

int			skip_env(char const *s)
{
	int		i;

	i = 0;
	while (s[i] && ft_isalpha(s[i]))
		i++;
	return (i);
}

/*
** en env[n - 1] le restamos uno porque hemos devuleto el índice +1
*/

void	ft_dollar_cpy(t_ints *a, char **env, char *str, char const *s)
{
	int		n;
	int		z;

	a->j++;
	if ((n = ft_check_dollar(&s[a->j], env)))
	{
		z = ft_strlen2(env[n - 1]) + 1;
		while (env[n - 1][z])
			str[a->i++] = env[n - 1][z++];
		a->j += skip_env(&s[a->j]);
	}
	else if (n == -1)
		str[a->i++] = '?';
	else
		a->j += skip_env(&s[a->j]);
}

/*
** en env[n - 1] le restamos uno porque hemos devuleto el índice +1
*/

void	ft_quotations_cpy(t_ints *a, char **env, char *str, char const *s)
{
	int		n;
	int		z;

	a->j++;
	while (s[a->j] && s[a->j] != '\"')
	{
		if (s[a->j] == '$' && (n = ft_check_dollar(&s[a->j + 1], env)))
		{
			z = ft_strlen2(env[n - 1]) + 1;
			while (env[n - 1][z])
				str[a->i++] = env[n - 1][z++];
			a->j += skip_env(&s[a->j + 1]);
		}
		else if (s[a->j] == '$')
			a->j += skip_env(&s[a->j + 1]);
		else
			str[a->i++] = s[a->j];
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

static int	ft_cpyword(char const *s, char **env, int j, char *str)
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
			ft_dollar_cpy(a, env, str, s);
		if (s[a->j] == '\"')
			ft_quotations_cpy(a, env, str, s);
		if (s[a->j] == '\'')
			ft_simpquotations_cpy(a, str, s);
		else if (s[a->j] && s[a->j] != c && s[a->j] != '$')
			str[a->i++] = s[a->j++];
	}
	str[a->i] = 0;
	n = a->j;
	free(a);
	return (n);
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
		j = ft_cpyword(s, t->env, j, tab[i]);
		i++;
	}
	return (tab);
}
