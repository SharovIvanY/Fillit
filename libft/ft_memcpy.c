/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:20:33 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/01 18:12:19 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	x;
	unsigned char	*dest2;
	unsigned char	*src2;

	x = 0;
	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	while (n > 0)
	{
		dest2[x] = src2[x];
		n--;
		x++;
	}
	return (dest2);
}
