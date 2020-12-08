/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:19:39 by isfernan          #+#    #+#             */
/*   Updated: 2020/12/08 18:37:01 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void			add_count_a(t_counts2 *c)
{
	c->a++;
	c->i++;
}

void			check_quotes2(t_counts2 *c, char *s)
{
	if (s[c->i] == '\"')
	{
		add_count_a(c);
		while (s[c->i] && s[c->i] != '\"')
			c->i++;
		if (s[c->i] == '\"')
			add_count_a(c);
	}
	else if (s[c->i] == '\'')
	{
		c->b++;
		c->i++;
		while (s[c->i] && s[c->i] != '\'')
			c->i++;
		if (s[c->i] == '\'')
		{
			c->b++;
			c->i++;
		}
	}
	else
		c->i++;
}

int				check_quotes(char *s)
{
	t_counts2	*c;

	if (!(c = malloc(sizeof(t_counts2))))
		return (0);
	c->a = 0;
	c->b = 0;
	c->i = 0;
	while (s[c->i])
		check_quotes2(c, s);
	if ((c->a % 2 != 0) || (c->b % 2 != 0))
	{
		free(c);
		return (0);
	}
	free(c);
	return (1);
}

char			*ft_strjoin_sl(const char *s1, const char *s2)
{
	int			pos;
	char		*dest;

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
	int			pos;
	char		*dest;

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
