/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:33:58 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/09 13:37:19 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	x;
	int	y;
	int len;

	x = 0;
	y = 0;
	if (needle[y] == 0)
		return ((char *)(haystack));
	len = ft_strlen(haystack);
	while (x <= len)
	{
		y = 0;
		if (haystack[x] == needle[y])
			while (haystack[y + x] == needle[y])
			{
				if (needle[y + 1] == '\0')
					return ((char *)(haystack + x));
				y++;
			}
		x++;
	}
	return (NULL);
}
