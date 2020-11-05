/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:12:06 by isfernan          #+#    #+#             */
/*   Updated: 2020/11/05 21:36:36 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int  need_to_remove(char *s, char **env)
{
	int     i;
	size_t     j;

	i = 0;
	while (env[i])
	{
		if (ft_strlen(s) == (j = ft_strlen2(env[i])) && ft_strncmp(s, env[i], j) == 0)
			return (i);
		i++;
	}
	return (0);
}

static char	**ft_remove(t_tab *t, int n)
{
	int		l;
	int		c;
	int		l2;
	char	**newenv;

	l = 0;
	while (t->env[l])
		l++;
	newenv = (char **)malloc(sizeof(char *) * l);
	newenv[l - 1] = NULL;
	l = 0;
	l2 = 0;
	while (t->env[l])
	{
		if (l == n)
		{
			l++;
			continue ;
		}
		else
		{
			c = -1;
			newenv[l2] = malloc(sizeof(char) * (ft_strlen(t->env[l]) + 1));
			newenv[l2][ft_strlen(t->env[l])] = '\0';
			while (t->env[l][++c])
				newenv[l2][c] = t->env[l][c];
		}
		l++;
		l2++;
	}
	return (newenv);
}

int			ft_unset(char **args, t_tab *t)
{
	int		i;
	int		n;

	i = 0;
	if (args[0])
	{
		while (args[i])
		{
			if ((n = need_to_remove(args[i], t->env)))
			{
				printf("%i\n", n);
				t->env = ft_remove(t, n);
			}
			i++;
		}
	}
	return (0);
}

