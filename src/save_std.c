/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_std.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:21:12 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/07 21:16:15 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save2_std(t_tab *t)
{
	t->save[0] = dup(STDIN_FILENO);
	t->save[1] = dup(STDOUT_FILENO);
}

void	reset_std23(t_tab *t)
{
	dup2(t->save[0], STDIN_FILENO);
	dup2(t->save[1], STDOUT_FILENO);
}

void	reset_stdout(t_tab *t)
{
	dup2(t->save[1], STDOUT_FILENO);
}
