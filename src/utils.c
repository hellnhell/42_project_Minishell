/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:19:39 by isfernan          #+#    #+#             */
/*   Updated: 2020/12/04 20:38:51 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_quotes(char *s)
{
	int		a;
	int		b;
	int		i;

	a = 0;
	b = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\"')
		{
			a++;
			i++;
			while (s[i] && s[i] != '\"')
				i++;
			if (s[i] == '\"')
			{
				a++;
				i++;
			}
		}
		else if (s[i] == '\'')
		{
			b++;
			i++;
			while (s[i] && s[i] != '\'')
				i++;
			if (s[i] == '\'')
			{
				b++;
				i++;
			}
		}
		else
			i++;
	}
	if ((a % 2 != 0) || (b % 2 != 0))
		return (0);
	return (1);
}

char			*ft_strjoin_sl(const char *s1, const char *s2)
{
	int		pos;
	char	*dest;

	if (!(dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 2)))
		return (NULL);
	pos = 0;
	while (*s1)
		dest[pos++] = *s1++;
	dest[pos++] = '/';
	while (*s2)
		dest[pos++] = *s2++;
	dest[pos] = '\0';
	return (dest);
}

char			*ft_strjoin_sl2(const char *s1, const char *s2)
{
	int		pos;
	char	*dest;

	if (!(dest = malloc(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	pos = 0;
	while (*s1)
		dest[pos++] = *s1++;
	if (*s2 == '.')
		s2++;
	else if (*s2 == '/')
		s2++;
	while (*s2)
		dest[pos++] = *s2++;
	dest[pos] = '\0';
	return (dest);
}
