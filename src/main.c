/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/10/20 18:37:28 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_line(t_tab *t)
{
	char	*line;

	// Aqui el line no hace nada?
	line = NULL;
	get_next_line(0, &t->line);
	return(t->line);
}

void	initt(t_tab *t)
{
	t->line = NULL;
	t->path = NULL;
}

int		main(int argc, char **argv, char **env)
{
	t_tab	*t;
	int		i;

	t = malloc(sizeof(t_tab));
	initt(t);
	(void)argc;
	(void)argv;
	while (1)
	{
		i = 0;
		ft_putstr_fd("marishell% ", 1);
		t->line = read_line(t);
		// Si ; está entre comillas no lo tiene que separar
		// Hay que comprobar primero que el número de comillas es par
		t->orders = ft_split(t->line, ';');
		while (t->orders[i])
		{
			t->tokens = ft_split_com(t->orders[i], ' ',t);
			// Una opcion es crear un proceso hijo por cada token
			// Hay que leer las variables de entorno antes del siguiente paso ($)
			if(check_our_implement(t))
			{
				read_path(t, env);
				check_path(t, env);
			}
			i++;
			// t_tokens se puede liberar asi a lo bestia o hay que ir linea por linea?
			free(t->tokens);
		}
		free(t->orders);
	}
}
