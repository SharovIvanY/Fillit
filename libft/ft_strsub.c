/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:40:05 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/02 14:13:28 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		x;
	int		size;
	char	*s2;

	if (!s)
		return (NULL);
	x = 0;
	size = len;
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (s[start] != 0 && size > 0)
	{
		s2[x] = s[start];
		start++;
		size--;
		x++;
	}
	s2[x] = 0;
	if (size == 0 || s[start] != 0)
	{
		return (s2);
	}
	return (NULL);
}
