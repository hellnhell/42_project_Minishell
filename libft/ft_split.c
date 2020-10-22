/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:42:37 by isfernan          #+#    #+#             */
/*   Updated: 2020/10/22 18:07:43 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* 
** Esta función es el split modificado para dividir los comandos (es decir, ';')
** pero ignorando los ; que están entre comillas
*/

// Hay qe comprobar si este gestiona bien que las comillas pegadas a cosas

static int	ft_countwords(char const *s, char c)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == '\"')
		{
			i++;
			while (s[i] && s[i] != '\"')
				i++;
			i++;
		}
		while (s[i] == '\'')
		{
			i++;
			while (s[i] && s[i] != '\'')
				i++;
			i++;
		}
		if (s[i] && s[i] == c)
		{
			i++;
			continue ;
		}
		counter++;
		while (s[i] && s[i] != c && s[i] != '\"' && s[i] != '\'')
		{
			i++;
			if (s[i] && s[i] == '\"')
			{
				i++;
				while (s[i] && s[i] != '\"')
					i++;
			}
			else if (s[i] && s[i] == '\'')
			{
				i++;
				while (s[i] && s[i] != '\'')
					i++;
			}
		}
	}
	return (counter);
}

static int	ft_size(char const *s, char c, int j)
{
	int		counter;

	counter = 0;
	while (s[j] == c)
		j++;
	while (s[j] && s[j] != c)
	{
		if (s[j] == '\"')
		{
			j++;
			while (s[j] && s[j] != '\"')
			{
				j++;
				counter++;
			}
			counter++;
		}
		else if (s[j] == '\'')
		{
			j++;
			while (s[j] && s[j] != '\'')
			{
				j++;
				counter++;
			}
			counter++;
		}
		counter++;
		j++;
	}
	//printf("%i\n", counter + 1);
	return (counter + 1);
}

static int	ft_cpyword(char const *s, char c, int j, char *str)
{
	int		i;

	i = 0;
	while (s[j] == c)
		j++;
	while (s[j] && s[j] != c)
	{
		if (s[j] == '\"')
		{
			str[i++] = s[j++];
			while (s[j] && s[j] != '\"')
				str[i++] = s[j++];
		}
		else if (s[j] == '\'')
		{
			str[i++] = s[j++];
			while (s[j] && s[j] != '\'')
				str[i++] = s[j++];
		}
		str[i++] = s[j++];
	}
	str[i] = 0;
	return (j);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**tab;

	j = 0;
	if (!s)
		return (NULL);
	i = ft_countwords(s, c);
	//printf("%i\n", i);
	if (!(tab = malloc(sizeof(char **) * (i + 1))))
		return (NULL);
	tab[i] = NULL;
	words = i;
	i = 0;
	while (i < words)
	{
		tab[i] = malloc(sizeof(char) * ft_size(s, c, j));
		j = ft_cpyword(s, c, j, tab[i]);
		i++;
	}
	return (tab);
}


int main()
{
	//char **s = ft_split(";;;;hola \"que;\" tal ; todo \';\' bien", ';');
	//printf("%s\n%s\n", s[0], s[1]);
	//ft_size(";;;;hola que tal ; hi \";\" no", ';', 0);
	int n;
	n = ft_countwords(";;;;\"hola\" \"que;\" tal ; todo \';\' bien", ';');
	printf("%i\n", n);
}

