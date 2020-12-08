/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_our_implement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:47:06 by nazurmen          #+#    #+#             */
/*   Updated: 2020/12/08 18:36:32 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		check_builtins(t_tab *t)
{
	if (check_our_implement(t))
		check_bash_implement(t);
}

void		check_bash_implement(t_tab *t)
{
	read_path(t);
	check_path(t);
}

int			check_our_implement(t_tab *t)
{
	if (!t->tokens[0])
		return (1);
	if (!ft_strncmp(t->tokens[0], "exit\0", 5))
		return (ft_exit(&t->tokens[1], t));
	if (!ft_strncmp(t->tokens[0], "pwd\0", 4))
		return (ft_pwd());
	if (!ft_strncmp(t->tokens[0], "cd\0", 3))
		return (ft_cd(&t->tokens[1], t->env));
	if (!ft_strncmp(t->tokens[0], "echo\0", 5))
		return (ft_echo(&t->tokens[1]));
	if (!ft_strncmp(t->tokens[0], "export\0", 7))
		return (ft_export(&t->tokens[1], t));
	if (!ft_strncmp(t->tokens[0], "env\0", 4))
		return (ft_env(t->env));
	if (!ft_strncmp(t->tokens[0], "unset\0", 6))
		return (ft_unset(&t->tokens[1], t));
	else
		return (1);
}
