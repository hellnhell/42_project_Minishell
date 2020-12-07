/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:56:47 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/07 21:14:56 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		err_change_env(char *var, char *val, char *str, t_tab *t)
{
	if (ft_isdigit(var[0]))
	{
		ft_printf("minishell: export: \'%s\': not a valid identifier\n", str);
		free(var);
		free(val);
		t->status = 1;
		return (1);
	}
	return (0);
}

void	err_nodir_pipe(char **str)
{
	ft_printf("minishell: %s: No such file or directory\n", str[0]);
	exit(1);
}

void	error_unex(t_tab *t)
{
	ft_printf("minishell: syntax error near unexpected token\n");
	t->status = 258;
	free_matrix(t->tokens);
}

void	not_command_error(t_tab *t)
{
	reset_std23(t);
	if (t->tokens[0][0] == '/')
		ft_printf("minishell: %s : No such file or directory\n", t->tokens[0]);
	else
		ft_printf("minishell: %s : command not found\n", t->tokens[0]);
	exit(127);
}
