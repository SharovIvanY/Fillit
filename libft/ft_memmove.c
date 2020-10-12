/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:27:20 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/03 18:21:42 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			proverka(const char *s1, char *s2)
{
	if (s1 == s2)
		return (0);
	else if (s1 > s2)
		return (0);
	else
		return (s1 - s2);
}

void				*ft_memmove(void *dest, const void *src,
								size_t len)
{
	char			*dest2;
	const char		*src2;
	size_t			x;

	x = 0;
	dest2 = (char*)dest;
	src2 = (const char*)src;
	if (proverka(src2, dest2))
	{
		while (len)
		{
			dest2[len - 1] = src2[len - 1];
			len--;
		}
	}
	else
		while (x < len)
		{
			dest2[x] = src2[x];
			x++;
		}
	return (dest);
}
