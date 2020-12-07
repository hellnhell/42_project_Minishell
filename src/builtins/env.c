/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:02:19 by isfernan          #+#    #+#             */
/*   Updated: 2020/12/07 21:14:00 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_cpy_env(char **env, t_tab *t)
{
	int		l;
	int		c;

	l = 0;
	while (env[l])
	{
		c = 0;
		while (env[l][c])
		{
			t->env[l][c] = env[l][c];
			c++;
		}
		t->env[l][c] = '\0';
		l++;
	}
}

void		ft_allocate_env(char **env, t_tab *t)
{
	int		l;
	int		c;

	l = 0;
	c = 0;
	while (env[l])
		l++;
	t->env = (char **)malloc(sizeof(char *) * (l + 1));
	t->env[l] = NULL;
	l = 0;
	while (env[l])
	{
		c = 0;
		while (env[l][c])
			c++;
		t->env[l] = (char *)malloc(sizeof(char) * (c + 1));
		l++;
	}
	ft_cpy_env(env, t);
}

int			ft_env(char **str)
{
	int		l;

	l = 0;
	while (str[l])
	{
		ft_printf("%s\n", str[l]);
		l++;
	}
	return (0);
}
