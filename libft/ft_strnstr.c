/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:21:11 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/14 15:55:21 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*f_return(const char *haystack, const char *needle,\
		size_t len, int x)
{
	int		y;
	int		len_stack;

	y = 0;
	len_stack = len;
	if (needle[y] == 0)
		return ((char *)(haystack));
	while (x <= (int)len)
	{
		y = 0;
		len_stack = len;
		if (haystack[x] == needle[y])
			while (haystack[y + x] == needle[y])
			{
				if (len-- <= 0)
					return (NULL);
				if (needle[y++ + 1] == '\0')
					return ((char *)(haystack + x));
			}
		len = len_stack;
		x++;
		len--;
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		x;

	x = 0;
	return (f_return(haystack, needle, len, x));
}
