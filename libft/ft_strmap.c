/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:08:06 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/09 13:29:53 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		x;
	char	*str;

	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	x = 0;
	while (s[x] != 0)
	{
		str[x] = f(s[x]);
		x++;
	}
	str[x] = 0;
	return (str);
}
