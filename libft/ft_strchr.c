/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:32:21 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/15 16:00:53 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	ch;
	int		x;
	int		len;

	len = ft_strlen(str);
	ch = c;
	x = 0;
	while (x <= len)
	{
		if (str[x] == ch)
			return ((char *)(str + x));
		x++;
	}
	return (NULL);
}
