/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/11/27 20:57:38 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	iterate_list(t_tab *t, List *list, char **env)
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
				ft_pipes(t, env);
		else if (t->index[t->i] && t->index[t->i] == '<' && t->index[t->i + 1]
				&& t->index[t->i + 1] == '|')
		{
			iterator = iterator->next;
			ft_redi_pipe(t, env, iterator);

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
	}
}

char	*read_line(t_tab *t)
{
	if (!get_next_line(0, &t->line))
		ft_signal_d(1);
	return(t->line);
}

void	initt(t_tab *t)
{
	t->z = 0;
	t->line = NULL;
	t->path = NULL;
	t->status = 0;
}

static int		check_quotes(char *s)
{
	int		a;
	int		b;
	int		i;
	int		ain;
	int		bin;

	a = 0;
	b = 0;
	i = 0;
	ain = 0;
	bin = 0;
	while (s[i])
	{
		if (s[i] == '\"')
		{
			a++;
			i++;
			while (s[i] && s[i] != '\"')
				i++;
			if (s[i] == '\"')
			{
				a++;
				i++;
			}
		}
		else if (s[i] == '\'')
		{
			b++;
			i++;
			while (s[i] && s[i] != '\'')
				i++;
			if (s[i] == '\'')
			{
				b++;
				i++;
			}
		}
		else
			i++;
	}
	if ((a % 2 != 0) || (b % 2 != 0))
		return (0);
	return (1);
	
}

int		main(int argc, char **argv, char **env)
{
	t_tab	*t;
	int		i;
	int		j;
	List	*list;
	
	
	(void)argc;
	(void)argv;
	if(!(t = malloc (sizeof(t_tab))))
		return (1);
	initt(t);
	ft_allocate_env(env, t);
	ft_cpy_env(env, t);
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
		while (t->orders[i])
		{
			//printf("la primera línea copiada es:|%s|\n", t->env[0]);
			save2_std(t);
			//fprintf(stderr, "la primera línea copiada es:|%s|\n", t->env[0]);
			list = new_list();
			create_list_elemnts(t, list, i);
			iterate_list(t, list, env);
			i++;
			reset_std23(t);
			ft_free_lists(list);
			free(t->index);
		}
		free_matrix(t->orders);
	}
}

void		free_matrix(char **matrix)
{
    int i;

    i = 0;
    while (matrix[i])
        i++;
    i--;
    while (i >= 0)
        free(matrix[i--]);
    free(matrix);
}
