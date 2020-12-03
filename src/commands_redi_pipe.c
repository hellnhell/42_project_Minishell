/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_redi_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:29:06 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/03 20:15:51 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redi_less_variants(Node *iterator, t_tab *t)
{
	if (t->index[t->i + 1] && t->index[t->i + 1] == '|')
	{
		t->iterator = t->iterator->next;
		ft_redi_pipe(t, t->iterator);
		t->i++;
	}
	else if ( t->index[t->i + 1] && (t->index[t->i + 1] == '>' || t->index[t->i + 1] == '-'))
	{
		ft_redi_redi(t, t->iterator, t->index[t->i + 1]);
		t->iterator = t->iterator->next;
	}
	else
	{
		if (t->index[t->i + 1] == '<' && t->index[t->i + 1] && t->tokens)
			t->iterator = t->iterator->next;
		t->iterator = t->iterator->next;
		ft_redi_less(t, t->iterator);	
	}
	t->i++;
}

void	commands_redi_pipes(t_tab *t, List *list)
{
	t->iterator = list->first;
	t->i = 0;
	while (t->iterator != NULL)
	{
		t->tokens = ft_split_list(t->iterator->element, ' ', t);
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
			t->iterator = t->iterator->next;
			ft_redi_less_variants(t->iterator, t);
		}
		else if (t->index[t->i] && t->index[t->i] == '>')
		{
			t->iterator = t->iterator->next;
			ft_redi_greater(t, t->iterator);
		}
		else if (t->index[t->i] && t->index[t->i] == '-')
		{
			t->iterator = t->iterator->next;			
			ft_redi_double(t, t->iterator);
		}
		else
			check_builtins(t);
		free_matrix(t->tokens);
		t->iterator = t->iterator->next;
		t->i++;
		//system("leaks minishell");
	}
}

/*void	commands_redi_pipes(t_tab *t, List *list)
{
	t->iterator = list->first;
	
	t->i = 0;
	while (t->iterator != NULL)
	{
		t->tokens = ft_split_list(t->iterator->element, ' ', t);
		printf("|%s|\n", t->iterator->element);
		printf("index-----%zu\n", ft_strlen(t->index));
		printf("list-----%d\n", size_list(list));
		if ((ft_strlen(t->index) + 1) != size_list(list))
		{
			ft_printf("marishell : syntax error near unexpected token\n");
			t->status = 258;
			return ;
		}
		if (t->index[t->i] && t->index[t->i] == '|')
				ft_pipes(t);
		else if (t->index[t->i] && t->index[t->i] == '<' && t->index[t->i + 1]
				&& t->index[t->i + 1] == '|')
		{
			t->iterator = t->iterator->next;
			ft_redi_pipe(t, t->iterator);

			free_matrix(t->tokens);
			t->iterator = t->iterator->next;
			t->tokens = ft_split_list(t->iterator->element, ' ', t);
			check_builtins(t, env);
			t->i++;
		}
		else if (t->index[t->i] && t->index[t->i] == '<' && t->index[t->i + 1]
				&& (t->index[t->i + 1] == '>' || t->index[t->i + 1] == '-'))
		{
			t->iterator = t->iterator->next;
			ft_redi_redi(t, t->iterator, t->index[t->i + 1]);
			t->iterator = t->iterator->next;
			//t->i++;
		}
		else if (t->index[t->i] && t->index[t->i] == '>')
		{
			t->iterator = t->iterator->next;
			ft_redi_greater(t, t->iterator);
		}
		else if (t->index[t->i] && t->index[t->i] == '<')
		{
			if (t->index[t->i + 1] == '<' && t->index[t->i + 1] && t->tokens)
				t->iterator = t->iterator->next;
			t->iterator = t->iterator->next;
			ft_redi_less(t, t->iterator);			
		}
		else if (t->index[t->i] && t->index[t->i] == '-')
		{
			t->iterator = t->iterator->next;			
			ft_redi_double(t, t->iterator);
		}
		else
			check_builtins(t);
		free_matrix(t->tokens);
		//free_matrix(t->path);
		t->iterator = t->iterator->next;
		t->i++;
	}
}
*/