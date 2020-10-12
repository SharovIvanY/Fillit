/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:01:33 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/15 18:15:50 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t x;
	size_t len_dest;

	x = 0;
	len_dest = 0;
	while (dest[x] != '\0' && x < size)
		x++;
	len_dest = x;
	if (x == size)
		return (len_dest + ft_strlen(src));
	while ((x < size - 1) && src[x - len_dest] != '\0')
	{
		dest[x] = (char)src[x - len_dest];
		x++;
	}
	dest[x] = '\0';
	return (len_dest + ft_strlen(src));
}
