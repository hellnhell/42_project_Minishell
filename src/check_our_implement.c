/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_our_implement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:47:06 by nazurmen          #+#    #+#             */
/*   Updated: 2020/11/04 19:22:18 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_our_implement(t_tab *t, char **env)
{
	if (!t->tokens[0])
		return (1);
	if (ft_strncmp(t->tokens[0], "pwd", 3) == 0 && ft_strlen(t->tokens[0]) == 3)
		return (ft_pwd());
	if (ft_strncmp(t->tokens[0], "cd", 2) == 0 && ft_strlen(t->tokens[0]) == 2)
		return (ft_cd(&t->tokens[1]));
	if (ft_strncmp(t->tokens[0], "echo", 4) == 0 && ft_strlen(t->tokens[0]) == 4)
		return (ft_echo(&t->tokens[1]));
	if (ft_strncmp(t->tokens[0], "export", 6) == 0 && ft_strlen(t->tokens[0]) == 6)
		return (ft_export(&t->tokens[1], t));
	if (ft_strncmp(t->tokens[0], "env", 3) == 0 && ft_strlen(t->tokens[0]) == 3)
		return (ft_env(t->env));
	if (ft_strncmp(t->tokens[0], "unset", 5) == 0 && ft_strlen(t->tokens[0]) == 5)
		return (ft_unset(&t->tokens[1], t));
	if (ft_strncmp(t->tokens[0], "exit", 4) == 0 && ft_strlen(t->tokens[0]) == 4)
		return (ft_exit(&t->tokens[1]));
	else
		return (1);

}
