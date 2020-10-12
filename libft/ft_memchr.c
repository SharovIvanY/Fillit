/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:13:04 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/03 18:06:31 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *str, int ch, size_t len)
{
	size_t			x;
	unsigned char	*str2;

	str2 = (unsigned char*)str;
	x = 0;
	while (x < len)
	{
		if (str2[x] == (unsigned char)ch)
			return ((void*)(str2 + x));
		x++;
	}
	return (NULL);
}
