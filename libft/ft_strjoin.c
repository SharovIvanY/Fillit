/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:45:15 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/09 13:34:49 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	int		len_s1;
	int		len_s2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	x = 0;
	y = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!str)
		return (NULL);
	x = 0;
	while (s1[x] != 0)
	{
		str[x] = s1[x];
		x++;
	}
	while (s2[y] != 0)
		str[x++] = s2[y++];
	str[x] = 0;
	return (str);
}
