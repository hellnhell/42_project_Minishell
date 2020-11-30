/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:13:54 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/30 19:20:33 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		ft_exit_args(char **args, int j)//PROBAR A METER NUESTRO PRINTF
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	if (ft_strncmp(args[0], "-", 1) == 0)
		i++;
	while (args[0][i])
	{
		if (ft_isdigit(args[0][i]) != 1)
		{
			ft_printf("mari: exit: %s : numeric argument required\n", args[0]);
			exit(255);
		}
		i++;
	}
	while (args[k])
	{
		if (++k > 1)
		{
			ft_printf("bash: exit: too many arguments\n");
			exit(1);
		}
	}
	exit(j);
}

int				ft_exit(char **args, t_tab *t)
{
	int			j;

	ft_printf("exit\n");
	if (args[0])
	{
		j = ft_atoi(args[0]);
		ft_exit_args(args, j);
	}
	else
	{
		system("leaks minishell");
		exit(t->status);
	}
	return (0);
}
