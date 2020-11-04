/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:37:44 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/04 12:45:55 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		pos;
	char	*dest;

	if (!(dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	pos = 0;
	while (*s1)
		dest[pos++] = *s1++;
	while (*s2)
		dest[pos++] = *s2++;
	dest[pos] = '\0';
	return (dest);
}
