/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 10:44:35 by emartin-          #+#    #+#             */
/*   Updated: 2020/01/08 12:58:06 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	t_tab		*tab;
	va_list		args;

	if (!(tab = malloc(sizeof(t_tab))))
		return (-1);
	va_start(args, format);
	tab->str = format;
	ft_initializate(tab);
	while (*(tab->str) != 0)
	{
		if (*(tab->str) == '%')
		{
			tab->str++;
			ft_check_flags(args, tab);
			ft_write_cases(tab, args);
		}
		else
			tab->len += write(1, tab->str, 1);
		if ((*(tab->str)))
			tab->str++;
	}
	va_end(args);
	return (tab->len);
}
