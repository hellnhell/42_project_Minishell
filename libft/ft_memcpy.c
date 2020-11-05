/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:29:07 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/05 21:11:40 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*aux1;
	unsigned char	*aux2;
	size_t			i;

	aux1 = (unsigned char *)src;
	aux2 = (unsigned char *)dst;
	if (dst == src || !n)
		return (dst);
	i = 0;
	while (i < n)
	{
		aux2[i] = aux1[i];
		i++;
	}
	return (dst);
}
