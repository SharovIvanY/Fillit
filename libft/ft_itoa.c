/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:17:09 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/11 05:57:02 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char static	*minus(int n)
{
	char	*str;

	n = -2147483648;
	str = (char*)malloc(sizeof(char) * 12);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = 0;
	return (str);
}

char static	*string_go(char *str, int znak, int x, int n)
{
	str[0] = (znak == -1 ? '-' : 0);
	str[x--] = 0;
	while (n > 9)
	{
		str[x--] = (n % 10) + 48;
		n /= 10;
	}
	str[x] = n + 48;
	return (str);
}

char		*ft_itoa(int n)
{
	int		res;
	int		znak;
	int		x;
	char	*str;

	if (n == -2147483648)
		return (minus(n));
	else if (n < -2147483647 || 0 > 2147483647)
		return (NULL);
	x = 0;
	znak = (n < 0 ? -1 : 1);
	n *= znak;
	res = n;
	x = (n == 0 ? 1 : 0);
	while (res > 0)
	{
		res /= 10;
		x++;
	}
	x = (znak == -1 ? x + 1 : x);
	str = (char*)malloc(sizeof(char) * x);
	if (!str)
		return (NULL);
	return (string_go(str, znak, x, n));
}
