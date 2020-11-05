/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:10:08 by emartin-          #+#    #+#             */
/*   Updated: 2020/01/07 17:38:56 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_cases(t_tab *tab, va_list args)
{
	if (*(tab->str) == 'd' || *(tab->str) == 'i')
		ft_putnbr_global(tab, args);
	else if (*(tab->str) == 's')
		ft_putstr_global(tab, args);
	else if (*(tab->str) == 'c')
		ft_putchar_global(tab, args);
	else if (*(tab->str) == 'x' || *(tab->str) == 'X')
		ft_puthex_global(tab, args);
	else if (*(tab->str) == 'p')
		ft_putpoint_global(tab, args);
	else if (*(tab->str) == 'u')
		ft_putunsigned_global(tab, args);
}
