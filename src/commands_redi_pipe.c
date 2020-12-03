/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_redi_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:29:06 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/03 17:58:20 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	ft_redi_less_variants(Node *iterator, t_tab *t)
{
	printf("%s\n", iterator->element);
	if (t->index[t->i + 1] && t->index[t->i + 1] == '|')
	{
		iterator = iterator->next;
		ft_redi_pipe(t, iterator);
		t->i++;
	}
	else if ( t->index[t->i + 1] && (t->index[t->i + 1] == '>' || t->index[t->i + 1] == '-'))
	{
		ft_redi_redi(t, iterator, t->index[t->i + 1]);
		fprintf(stderr, "1-----%s\n", iterator->element);
		iterator = iterator->next;
		fprintf(stderr, "2-----%s\n", iterator->element);
	}
	else
	{
		if (t->index[t->i + 1] == '<' && t->index[t->i + 1] && t->tokens)
			iterator = iterator->next;
		iterator = iterator->next;
		ft_redi_less(t, iterator);	
	}
	t->i++;
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
			iterator = iterator->next;
			ft_redi_less_variants(iterator, t);
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
		fprintf(stderr, "aaaa-----%s\n", iterator->element);
		iterator = iterator->next;
		t->i++;
		//system("leaks minishell");
	}
}
*/
void	commands_redi_pipes(t_tab *t, List *list)
{
	Node *iterator = list->first;
	
	t->i = 0;
	while (iterator != NULL)
	{
		t->tokens = ft_split_list(iterator->element, ' ', t);
		//printf("|%s|\n", iterator->element);
		//printf("index-----%zu\n", ft_strlen(t->index));
		//printf("list-----%d\n", size_list(list));
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
			iterator = iterator->next;
			ft_redi_pipe(t, iterator);

			/*free_matrix(t->tokens);
			iterator = iterator->next;
			t->tokens = ft_split_list(iterator->element, ' ', t);
			check_builtins(t, env);*/
			t->i++;
		}
		else if (t->index[t->i] && t->index[t->i] == '<' && t->index[t->i + 1]
				&& (t->index[t->i + 1] == '>' || t->index[t->i + 1] == '-'))
		{
			iterator = iterator->next;
			ft_redi_redi(t, iterator, t->index[t->i + 1]);
			iterator = iterator->next;
			//t->i++;
		}
		else if (t->index[t->i] && t->index[t->i] == '>')
		{
			iterator = iterator->next;
			ft_redi_greater(t, iterator);
		}
		else if (t->index[t->i] && t->index[t->i] == '<')
		{
			if (t->index[t->i + 1] == '<' && t->index[t->i + 1] && t->tokens)
				iterator = iterator->next;
			iterator = iterator->next;
			ft_redi_less(t, iterator);			
		}
		else if (t->index[t->i] && t->index[t->i] == '-')
		{
			iterator = iterator->next;			
			ft_redi_double(t, iterator);
		}
		else
			check_builtins(t);
		free_matrix(t->tokens);
		//free_matrix(t->path);
		iterator = iterator->next;
		t->i++;
	}
}