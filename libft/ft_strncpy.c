/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:10:36 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/09 13:35:27 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	x;

	x = 0;
	while (x < len && src[x] != '\0')
	{
		dst[x] = src[x];
		x++;
	}
	while (x < len)
	{
		dst[x] = 0;
		x++;
	}
	return (dst);
}
