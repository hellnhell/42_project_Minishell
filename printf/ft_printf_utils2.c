/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:05:37 by isfernan          #+#    #+#             */
/*   Updated: 2020/02/25 18:09:51 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_nb_z(int nb, int j)
{
	int				rtrn;
	long long int	i;

	rtrn = 0;
	i = 1;
	while (nb / i)
	{
		i = i * j;
		rtrn++;
	}
	if (nb <= 0)
		rtrn = rtrn + 1;
	return (rtrn);
}

int		count_nb_z2(int nb, int j)
{
	int				rtrn;
	long long int	i;

	if (nb == 0)
		return (1);
	rtrn = 0;
	i = 1;
	while (nb / i)
	{
		i = i * j;
		rtrn++;
	}
	return (rtrn);
}

int		count_nbu(unsigned int nb, int j)
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

int		count_nbuu(unsigned int nb, int j)
{
	int				rtrn;
	long long int	i;

	if (nb == 0)
		return (1);
	rtrn = 0;
	i = 1;
	while (nb / i)
	{
		i = i * j;
		rtrn++;
	}
	return (rtrn);
}

int		count_nbu2(unsigned long nb, int j)
{
	int					rtrn;
	unsigned long long	i;

	if (nb == 0)
		return (1);
	rtrn = 0;
	i = 1;
	while (nb / i)
	{
		i = i * j;
		rtrn++;
	}
	return (rtrn);
}
