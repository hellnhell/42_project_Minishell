/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_redi_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:29:06 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/04 20:34:10 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	commands_redi_pipes_3(t_tab *t)
{
	if (t->index[t->i] && t->index[t->i] == '|')
		ft_pipes(t);
	else
		check_builtins(t);
}

void	commands_redi_pipes_2(t_tab *t)
{
	if (t->index[t->i] && t->index[t->i] == '>')
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
		commands_redi_pipes_3(t);
}

void	error_unex(t_tab *t)
{
	ft_printf("marishell : syntax error near unexpected token\n");
	t->status = 258;
}

int		redi_less_return(t_tab *t)
{
	int		fd;
	char	**str;

	if (t->index[t->i] && t->index[t->i] == '<')
	{
		while (t->index[t->i + 1] == '<' && t->index[t->i + 1] && t->tokens)
		{
			t->i++;
			t->iterator = t->iterator->next;
			str = ft_split_list(t->iterator->element, ' ', t);
			fd = open(str[0], O_RDONLY);
			if (fd == -1)
			{
				ft_printf("mari: %s: No such file or directory\n", str[0]);
				free_matrix(str);
				t->status = 1;
				free_matrix(t->tokens);
				return (1);
			}
			free_matrix(str);
		}
		t->iterator = t->iterator->next;
		ft_redi_less(t, t->iterator);
	}
	return (0);
}

void	other_redi_less(t_tab *t)
{
	if (t->index[t->i + 1] && t->index[t->i + 1] == '|')
	{
		t->iterator = t->iterator->next;
		ft_redi_pipe(t, t->iterator);
		t->i++;
	}
	else if (t->index[t->i + 1]
		&& (t->index[t->i + 1] == '>' || t->index[t->i + 1] == '-'))
	{
		t->iterator = t->iterator->next;
		ft_redi_redi(t, t->iterator, t->index[t->i + 1]);
		t->iterator = t->iterator->next;
	}
}

void	commands_redi_pipes(t_tab *t, List *list)
{
	while (t->iterator != NULL)
	{
		t->tokens = ft_split_list(t->iterator->element, ' ', t);
		if ((ft_strlen(t->index) + 1) != size_list(list))
		{
			error_unex(t);
			return ;
		}
		else if (t->index[t->i] && t->index[t->i] == '<')
			other_redi_less(t);
		else
		{
			if (redi_less_return(t))
				return ;
			commands_redi_pipes_2(t);
		}
		free_matrix(t->tokens);
		t->iterator = t->iterator->next;
		t->i++;
	}
}

/* Este no sabemos cuál es pero no funcionan varios pipes */
/*void	commands_redi_pipes(t_tab *t, List *list)
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

			free_matrix(t->tokens);
			iterator = iterator->next;
			t->tokens = ft_split_list(iterator->element, ' ', t);
			check_builtins(t);
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
}*/
