/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:29:06 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/30 21:52:27 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	iterate_orders(t_tab *t, List *list, char **env, int i)
{
	while (t->orders[i])
	{
		save2_std(t);
		list = new_list();
		create_list_elemnts(t, list, i);
		iterate_list(t, list, env);
		i++;
		reset_std23(t);
		ft_free_lists(list);
		free(t->index);
	}
	free_matrix(t->orders);
	//free_matrix2(t->path, t);
}

void	iterate_list(t_tab *t, List *list, char **env)
{
	Node *iterator = list->first;
	
	t->i = 0;
	while (iterator != NULL)
	{
		t->tokens = ft_split_list(iterator->element, ' ', t);
		if ((ft_strlen(t->index) + 1) != size_list(list))
		{
			ft_printf("marishell : syntax error near unexpected token\n");
			t->status = 258;
			return ;
		}
		if (t->index[t->i] && t->index[t->i] == '|')
				ft_pipes(t, env);
		else if (t->index[t->i] && t->index[t->i] == '<' && t->index[t->i + 1]
				&& t->index[t->i + 1] == '|')
		{
			iterator = iterator->next;
			ft_redi_pipe(t, env, iterator);
			t->i++;
		}
		else if (t->index[t->i] && t->index[t->i] == '<' && t->index[t->i + 1]
				&& (t->index[t->i + 1] == '>' || t->index[t->i + 1] == '-'))
		{
			iterator = iterator->next;
			ft_redi_redi(t, env, iterator, t->index[t->i + 1]);
			iterator = iterator->next;
		}
		else if (t->index[t->i] && t->index[t->i] == '>')
		{
			iterator = iterator->next;
			ft_redi_greater(t, env, iterator);
		}
		else if (t->index[t->i] && t->index[t->i] == '<')
		{
			if (t->index[t->i + 1] == '<' && t->index[t->i + 1] && t->tokens)
				iterator = iterator->next;
			iterator = iterator->next;
			ft_redi_less(t, env, iterator);			
		}
		else if (t->index[t->i] && t->index[t->i] == '-')
		{
			iterator = iterator->next;			
			ft_redi_double(t, env, iterator);
		}
		else
			check_builtins(t, env);
		free_matrix(t->tokens);
		iterator = iterator->next;
		t->i++;
		t->z++;
		//system("leaks minishell");
	}
	//free_matrix(t->path);
}
