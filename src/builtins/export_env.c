/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:18:53 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/07 21:20:18 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_cpy_newenv2(char *var, char *val, char **newenv, int w)
{
	int		c;

	c = -1;
	while (*var)
		newenv[w][++c] = *var++;
	newenv[w][++c] = '=';
	while (*val)
		newenv[w][++c] = *val++;
	return (-1);
}

void		ft_cpy_newenv(char **env, char **newenv, char *var, char *val)
{
	int		l;
	int		c;
	int		w;
	int		z;

	l = 0;
	w = 0;
	z = 0;
	while (env[l])
		l++;
	while (z < l)
	{
		if (w + 2 != l)
		{
			c = -1;
			while (env[z][++c])
				newenv[w][c] = env[z][c];
		}
		else
			z = z + ft_cpy_newenv2(var, val, newenv, w);
		w++;
		z++;
	}
}

static char		**ft_realloc2(t_tab *t, t_counts *f, int k)
{
	char		**newenv;
	int			c;

	newenv = (char **)malloc(sizeof(char *) * (f->y + 2));
	newenv[f->y + 1] = NULL;
	while (f->j < f->y)
	{
		if (f->x + 2 != f->y)
		{
			c = 0;
			while (t->env[f->j][c])
				c++;
			newenv[f->x] = (char *)malloc(sizeof(char) * (c + 1));
			newenv[f->x][c] = '\0';
		}
		else
		{
			newenv[f->x] = (char *)malloc(sizeof(char) * k);
			newenv[f->x][k - 1] = '\0';
			f->j--;
		}
		f->x++;
		f->j++;
	}
	return (newenv);
}

char			**ft_realloc_env(t_tab *t, char *var, char *val, int k)
{
	t_counts	*f;
	char		**newenv;
	int			c;

	f = malloc(sizeof(t_counts));
	f->y = 0;
	f->x = 0;
	f->j = 0;
	while (t->env[f->y])
		f->y++;
	newenv = ft_realloc2(t, f, k);
	ft_cpy_newenv(t->env, newenv, var, val);
	free_matrix(t->env);
	free(f);
	return (newenv);
}
