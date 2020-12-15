/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:50:42 by isfernan          #+#    #+#             */
/*   Updated: 2020/02/25 17:01:13 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_nbru(unsigned int nb, t_data *data)
{
	long long int	i;
	char			z;

	i = 1;
	if (nb == 0)
	{
		putsmpl('0', data);
		return ;
	}
	while (nb / i)
		i = i * 10;
	while (i / 10)
	{
		z = (nb % i) / (i / 10) + '0';
		i = i / 10;
		putsmpl(z, data);
	}
}

void	put_str(char *str, t_data *data)
{
	int				i;

	i = -1;
	while (str[++i])
	{
		data->printed++;
		write(1, &str[i], 1);
	}
}

void	put_str_len(char *str, int z, t_data *data)
{
	int				i;

	i = -1;
	while (str[++i] && i < z)
	{
		data->printed++;
		write(1, &str[i], 1);
	}
}

void	put_nbr_long(long nb, t_data *data)
{
	unsigned int	l;
	long long int	i;
	char			z;

	i = 1;
	if (nb == 0)
	{
		putsmpl('0', data);
		return ;
	}
	if (nb < 0)
	{
		putsmpl('-', data);
		l = nb * (-1);
	}
	else
		l = nb;
	while (l / i)
		i = i * 10;
	while (i / 10)
	{
		z = (l % i) / (i / 10) + '0';
		i = i / 10;
		putsmpl(z, data);
	}
}
