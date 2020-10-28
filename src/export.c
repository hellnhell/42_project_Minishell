/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:30:04 by isfernan          #+#    #+#             */
/*   Updated: 2020/10/28 20:15:00 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	ft_change_env(char *str, t_tab *t)
{
	char	*var;
	char	*val;
	int		i;
	int		j;
	int		z;

	j = 0;
	i = ft_strlen2(str);
	var = malloc(sizeof(char) * (i + 1));
	z = ft_strlen(str + i + 1);
	val = malloc(sizeof(char) * (z + 1));
	ft_strpncpy(var, str, i);
	ft_strpncpy(val, str + i + 1, z);
	if (ft_isdigit(var[0]))
		printf("bash: export: \'%s\': not a valid identifier", str);
	while (t->env[j])
	{
		if (ft_strlen2(t->env[j]) == i && ft_strncmp(t->env[j], var, i) == 0)
		{
			i = 0;
			while (*var)
			{
				t->env[j][i++] = *var;
				var++;
			}
			t->env[j][i++] = '=';
			while (*val)
			{
				t->env[j][i++] = *val;
				val++;
			}
			t->env[j][i] = '\0';
			printf("env[j]=%s\n", t->env[j]);
		}
		j++;
	}
	/*if (!t->env[j])
		Aquí hay que copiarlo todo */
}

int		ft_export(char **args, t_tab *t)
{
	int		i;
	
	i = 0;
	if (!args[0])
		ft_no_options(t);
	else
	{
		while (args[i])
		{
			if (ft_strchr(args[i], '=')) // Aquí hay un igual
				ft_change_env(args[i], t);
			i++;
		}
	}
	return (0);
}
