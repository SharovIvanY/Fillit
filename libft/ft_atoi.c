/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:34:22 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/15 17:23:03 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int x;
	int result;
	int znak;

	x = 0;
	result = 0;
	znak = 0;
	while (str[x] == '\f' || str[x] == '\n' || str[x] == '\r' || str[x] == '\t'\
		|| str[x] == '\v' || str[x] == ' ')
		x++;
	if ((str[x] == '-' || str[x] == '+') && znak == 0)
	{
		if (str[x] == '-')
			znak = -1;
		else if (str[x] == '+')
			znak = 1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		result = result * 10 + (str[x] - '0');
		x++;
	}
	return (result = (znak == -1 ? result * -1 : result));
}
