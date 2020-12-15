/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:30:04 by isfernan          #+#    #+#             */
/*   Updated: 2020/12/09 18:16:33 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_no_options(t_tab *t)
{
	int		i;
	int		j;

	i = 0;
	while (t->env[i])
	{
		j = -1;
		ft_putstr_fd("declare -x ", 1);
		while (t->env[i][++j] != '=')
			ft_putchar_fd(t->env[i][j], 1);
		ft_putstr_fd("=\"", 1);
		while (t->env[i][j++])
			ft_putchar_fd(t->env[i][j], 1);
		ft_putstr_fd("\"\n", 1);
		i++;
	}
}

static int	ft_check_export(t_tab *t, char *var, char *val, int j)
{
	int		i;
	int		z;

	i = ft_strlen(var);
	z = ft_strlen(val);
	if ((int)ft_strlen2(t->env[j]) == i && ft_strncmp(t->env[j], var, i) == 0)
	{
		free(t->env[j]);
		t->env[j] = malloc(sizeof(char) * (i + z + 2));
		i = 0;
		while (var[i])
		{
			t->env[j][i] = var[i];
			i++;
		}
		t->env[j][i++] = '=';
		z = 0;
		while (val[z])
			t->env[j][i++] = val[z++];
		t->env[j][i] = '\0';
		return (1);
	}
	return (0);
}

static void	ft_change_env(char *str, t_tab *t)
{
	char	*var;
	char	*val;
	int		j;

	j = 0;
	var = malloc(sizeof(char) * (ft_strlen2(str) + 1));
	val = malloc(sizeof(char) * (ft_strlen(str + ft_strlen2(str) + 1) + 1));
	ft_strpncpy(var, str, ft_strlen2(str));
	ft_strpncpy(val, str + ft_strlen2(str) + 1,
		ft_strlen(str + ft_strlen2(str) + 1));
	if (err_change_env(var, val, str, t))
		return ;
	while (t->env[j])
	{
		if (ft_check_export(t, var, val, j))
			break ;
		j++;
	}
	if (!t->env[j])
		t->env = ft_realloc_env(t, var, val, ft_strlen(var)
			+ ft_strlen(val) + 2);
	free(var);
	free(val);
}

int			ft_export(char **args, t_tab *t)
{
	int		i;

	i = 0;
	if (!args[0])
		ft_no_options(t);
	else
	{
		while (args[i])
		{
			if (ft_strchr(args[i], '='))
				ft_change_env(args[i], t);
			i++;
		}
	}
	return (0);
}
