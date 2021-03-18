/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_orders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:52:11 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/09 18:05:20 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		create_orders(t_tab *t, t_lista *lst, int i)
{
	while (t->orders[i])
	{
		save2_std(t);
		lst = new_list();
		create_list_elemnts(t, lst, i);
		t->iterator = lst->first;
		t->i = 0;
		commands_redi_pipes(t, lst);
		i++;
		reset_std23(t);
		ft_free_lists(lst);
		free(t->index);
	}
	free_matrix(t->orders);
}

void		ft_minishell(t_tab *t, t_lista *lst)
{
	int		i;

	while (1)
	{
		i = 0;
		ft_putstr_fd(PROMPT, 1);
		signal(SIGINT, ft_signal_c);
		signal(SIGQUIT, ft_signal_c);
		t->line = read_line(t);
		if (!check_quotes(t->line))
		{
			ft_printf("minishell : bad number of quotes\n");
			free(t->line);
			continue ;
		}
		t->orders = ft_split(t->line, ';');
		free(t->line);
		create_orders(t, lst, i);
	}
}
