/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/12/01 20:26:06 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
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

static void		ft_minishell(t_tab *t, List *list)
{
	int			i;
	
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
		iterate_orders(t, list, i);//CAMBIADO
	}
}


char	*read_line(t_tab *t)
{
	if (!get_next_line(0, &t->line))
		ft_signal_d(1);
	return(t->line);
}

void	initt(t_tab *t, char **env)
{
	t->z = 0;
	t->line = NULL;
	t->path = NULL;
	t->status = 0;
	ft_allocate_env(env, t);//CAMBIADO
}

int		main(int argc, char **argv, char **env)
{
	t_tab	*t;
	List	*list;
	
	list = NULL;
	(void)argc;
	(void)argv;
	if(!(t = malloc (sizeof(t_tab))))
		return (1);
	initt(t, env);
	ft_minishell(t, list);
}
