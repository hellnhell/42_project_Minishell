/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:53:01 by isfernan          #+#    #+#             */
/*   Updated: 2020/10/23 21:27:30 by isfernan         ###   ########.fr       */
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

// He cambiado esta función aquí pero en el otro split no!!!!

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
			if (s[i] == c)
				counter++;
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
		if (!(n = ft_strncmp(s, env[i], j)) && (!s[j] || s[j] == ' ' || s[j] == '\"' || s[j] == '\'' || s[j] == '$'))
		{
			n = ft_strlen(env[i] + j + 1) - j; // Le quitamos 1 por el dólar
			return (n);
		}
		i++;
	}
	return (0);
}

static int	ft_size(char const *s, char c, int j, char **env)
{
	int		counter;
	int		n;

	counter = 0;
	while (s[j] == c)
		j++;
	while (s[j] && s[j] != c)
	{
		n = 1;
		if (s[j] == '$')
		{
			n = ft_dollar_count(&s[j + 1], env);
			counter += n;
			j++;
			if (n == 0)
				while (s[j] && s[j] != ' ' && s[j] != '\"' && s[j] != '\'' && s[j] != '$')
					j++;
		}
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
		if (n != 0)
		{
			counter++;
			j++;
		}
	}
	return (counter + 1);
}

int			ft_check_dollar(char const *s, char **env)
{
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		j = ft_strlen2(env[i]);
		if (!(ft_strncmp(s, env[i], j)) && (!s[j] || s[j] == ' ' || s[j] == '\"' || s[j] == '\'' || s[j] == '$'))
			return (i + 1); // Devolvemos i + 1 porque la i puede ser 0 y no queremos devolver 0 si lo hemos encontrado
		i++;
	}
	return (0);
}

int		ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
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

static int	ft_cpyword(char const *s, char **env, int j, char *str)
{
	int		i;
	char	c;
	int		n;
	int		z;

	i = 0;
	c = ' ';
	while (s[j] == c)
		j++;
	while (s[j] && s[j] != c)
	{
		if (s[j] == '$')
		{
			j++;
			if ((n = ft_check_dollar(&s[j], env)))
			{
				z = ft_strlen2(env[n - 1]) + 1;
				while (env[n - 1][z]) // Le restamos 1 porque hemos devuelto el índice + 1
					str[i++] = env[n - 1][z++];
			}
		}
		if (s[j] == '\"')
		{
			j++;
			while (s[j] && s[j] != '\"')
			{
				if (s[j] == '$' && (n = ft_check_dollar(&s[j], env)))
				{
					z = ft_strlen2(env[n - 1]) + 1;
					while (env[n - 1][z]) // Le restamos 1 porque hemos devuelto el índice + 1
						str[i++] = env[n - 1][z++];
					j += skip_env(&s[j]);
				}
				else
					str[i++] = s[j];
				j++;
			}
			j++;
		}
		if (s[j] == '\'')
		{
			j++;
			while (s[j] && s[j] != '\'')
			{
				str[i++] = s[j++];
			}
			j++;
		}
		else if (s[j] && s[j] != c)
			str[i++] = s[j++];
	}
	str[i] = 0;
	return (j);
}

char		**ft_split_list(char const *s, char c, char **env)
{
	int		i;
	int		j;
	int		words;
	int		p;
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
		tab[i] = malloc(sizeof(char) * (p = ft_size(s, c, j, env)));
		j = ft_cpyword(s, env, j, tab[i]);
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
	//n = ft_countwords("hola    \"que tal\"  colosal", ' ', str);
	//printf("%i\n", n);
	//n = ft_size("hola  s\"que     tal\"rt", ' ', 4, env);
	//n = ft_size("\" hola  \"",' ', 0, env);
	str = ft_split_list("$LOGNAME \"que   \" tal", ' ', env);
	n = 0;
	while (str[n])
	{
		printf("|%s|\n", str[n]);
		n++;
	}
}
