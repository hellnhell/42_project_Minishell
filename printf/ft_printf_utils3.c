/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:07:58 by isfernan          #+#    #+#             */
/*   Updated: 2020/02/25 17:08:20 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_min_2(int a, int b)
{
	if (a == -1)
		return (b);
	if (a < b)
		return (a);
	return (b);
}

int		ft_abs(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}

void	to_base(unsigned int nb, char *base, t_data *data)
{
	if (nb >= (unsigned int)ft_strlen(base))
		to_base(nb / (ft_strlen(base)), base, data);
	putchr_add(nb % ft_strlen(base), base, data);
}

void	to_base2(unsigned long nb, char *base, t_data *data)
{
	if (nb >= (unsigned long)ft_strlen(base))
		to_base2(nb / (ft_strlen(base)), base, data);
	putchr_add(nb % ft_strlen(base), base, data);
}

int		count_nb(int nb, int j)
{
	int				rtrn;
	long long int	i;

	if (nb == 0)
		return (0);
	rtrn = 0;
	i = 1;
	while (nb / i)
	{
		i = i * j;
		rtrn++;
	}
	return (rtrn);
}
