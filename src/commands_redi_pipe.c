/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_redi_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:29:06 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/02 21:19:48 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redi_less_variants(Node *iterator, t_tab *t)
{
	if (t->index[t->i + 1] && t->index[t->i + 1] == '|')
	{
		iterator = iterator->next;
		ft_redi_pipe(t, iterator);
		t->i++;
	}
	else if ( t->index[t->i + 1] && (t->index[t->i + 1] == '>' || t->index[t->i + 1] == '-'))
	{
		iterator = iterator->next;
		ft_redi_redi(t, iterator, t->index[t->i + 1]);
		iterator = iterator->next;
	}
	else
	{
		if (t->index[t->i + 1] == '<' && t->index[t->i + 1] && t->tokens)
			iterator = iterator->next;
		iterator = iterator->next;
		ft_redi_less(t, iterator);	
	}
}

void	commands_redi_pipes(t_tab *t, List *list)
{
	Node *iterator = list->first;
	
	t->i = 0;
	while (iterator != NULL)
	{
		t->tokens = ft_split_list(iterator->element, ' ', t);
		if ((ft_strlen(t->index) + 1) != (unsigned int)size_list(list))
		{
			ft_printf("marishell : syntax error near unexpected token\n");
			t->status = 258;
			return ;
		}
		if (t->index[t->i] && t->index[t->i] == '|')	
			ft_pipes(t);
		else if (t->index[t->i] && t->index[t->i] == '<')
		{
			ft_redi_less_variants(iterator, t);
			iterator = iterator->next;
		}
		else if (t->index[t->i] && t->index[t->i] == '>')
		{
			iterator = iterator->next;
			ft_redi_greater(t, iterator);
		}
		else if (t->index[t->i] && t->index[t->i] == '-')
		{
			iterator = iterator->next;			
			ft_redi_double(t, iterator);
		}
		else
			check_builtins(t);
		free_matrix(t->tokens);
		iterator = iterator->next;
		t->i++;
		//system("leaks minishell");
	}
}
