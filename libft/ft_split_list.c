/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:53:01 by isfernan          #+#    #+#             */
/*   Updated: 2020/10/22 19:38:40 by isfernan         ###   ########.fr       */
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

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t		ft_strlen2(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	return (i);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	
	while ((s1[i] && s2[i]) && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	ft_countwords(char const *s, char c, char **env)
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
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		counter++;
		while (s[i] && s[i] != c)
		{
			i++;
			if (s[i] && s[i] == '\"')
			{
				i++;
				while (s[i] && s[i] != '\"')
					i++;
			}
		}
	}
	return (counter);
}

/*
** Esta función recibe una cadena cuyo primer caracter es el
** que va después de $ y devuelve el valor de la cadena de 
**  caracteres por la que vamos a tener que sustituir la 
** variable de ambiente correspondiente
*/

int			ft_dollar_count(char const *s, char **env)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	while (env[i])
	{
		j = ft_strlen2(env[i]);
		if (!(n = ft_strncmp(s, env[i], j)) && (!s[j] || s[j] == ' ' || s[j] == '\"' || s[j] == '\''))
		{
			n = ft_strlen(env[i] + j + 1) - 1 - j; // Le quitamos 1 por el dólar
			return (n);
		}
		i++;
	}
	return (0);
	// Aquí hay que ver qué hacemos si no hemos encontrado la variable de ambiente
}

static int	ft_size(char const *s, char c, int j, char **env)
{
	int		counter;

	counter = 0;
	while (s[j] == c)
		j++;
	while (s[j] && s[j] != c)
	{
		if (s[j] == '$')
			counter += ft_dollar_count(&s[j + 1], env);
		if (s[j] == '\"')
		{
			j++;
			while (s[j] && s[j] != '\"')
			{
				j++;
				counter++;
			}
			counter = counter - 1;
		}
		counter++;
		j++;
	}
	return (counter + 1);
}

static int	ft_cpyword(char const *s, char c, int j, char *str)
{
	int		i;

	i = 0;
	while (s[j] == c)
		j++;
	while (s[j] && s[j] != c)
		str[i++] = s[j++];
	str[i] = 0;
	return (j);
}

char		**ft_split_list(char const *s, char c, char **env)
{
	int		i;
	int		j;
	int		words;
	char	**tab;

	j = 0;
	if (!s)
		return (NULL);
	i = ft_countwords(s, c, env);
	if (!(tab = malloc(sizeof(char **) * (i + 1))))
		return (NULL);
	tab[i] = NULL;
	words = i;
	i = 0;
	while (i < words)
	{
		tab[i] = malloc(sizeof(char) * ft_size(s, c, j, env));
		j = ft_cpyword(s, c, j, tab[i]);
		i++;
	}
	return (tab);
}

int main(int argc, char **argv, char **env)
{
	char	**str;
	int		n;

	(void)argc;
	(void)argv;
	//n = ft_countwords("hola  \"que     tal\"", ' ', str);
	//n = ft_size("hola  s\"que     tal\"rt", ' ', 4, env);
	n = ft_size("$LOGNAME",' ', 0, env);
	printf("%i\n", n);
}
