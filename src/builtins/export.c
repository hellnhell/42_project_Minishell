/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:30:04 by isfernan          #+#    #+#             */
/*   Updated: 2020/11/05 21:36:30 by hellnhell        ###   ########.fr       */
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

static void	ft_cpy_newenv(char **env, char **newenv, char *var, char *val)
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
		{
			c = -1;
			while (*var)
				newenv[w][++c] = *var++;
			newenv[w][++c] = '=';
			while (*val)
				newenv[w][++c] = *val++;
			z--;
		}
		w++;
		z++;
		//free(env[w]);
	}
	//free(env);
}

static char	**ft_realloc_env(t_tab *t, char *var, char *val, int x)
{
	char 	**newenv;
	int		l;
	int		c;
	int		w;
	int		z;

	l = 0;
	w = 0;
	z = 0;
	while (t->env[l])
		l++;
	newenv = (char **)malloc(sizeof(char *) * (l + 2)); // Le sumamos uno por el nulo y otro por la nueva variable
	newenv[l + 1] = NULL;
	while (z < l)
	{
		if (w + 2 != l)
		{
			c = 0;
			while (t->env[z][c])
				c++;
			newenv[w] = (char *)malloc(sizeof(char) * (c + 1));
			newenv[w][c] = '\0';
		}
		else
		{
			printf("este es el %i\n", w);
			newenv[w] = (char *)malloc(sizeof(char) * x);
			newenv[w][x - 1] = '\0';
			z--;
		}
		w++;
		z++;
	}
	ft_cpy_newenv(t->env, newenv, var, val);
	return (newenv);
}

static void	ft_change_env(char *str, t_tab *t)
{
	char	*var;
	char	*val;
	size_t		i;
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
	{
		printf("bash: export: \'%s\': not a valid identifier", str);
		return ;
	}
	while (t->env[j])
	{
		if (ft_strlen2(t->env[j]) == i && ft_strncmp(t->env[j], var, i) == 0)
		{
			free(t->env[j]);
			t->env[j] = malloc(sizeof(char) * (i + z + 2));
			i = 0;
			while (*var)
				t->env[j][i++] = *var++;
			t->env[j][i++] = '=';
			//printf("el env[j] de ahora |%s| %i\n", t->env[j], j);
			while (*val)
				t->env[j][i++] = *val++;
			t->env[j][i] = '\0';
			//printf("env[j]:%s\n", t->env[j]);
			break ;
		}
		j++;
	}
	if (!t->env[j])
		t->env = ft_realloc_env(t, var, val, i + z + 2);
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
