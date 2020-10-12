/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:39:13 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/02 16:49:55 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	int				x;
	unsigned char	*str2;

	str2 = (unsigned char*)str;
	x = 0;
	while (len-- > 0)
		str2[x++] = 0;
}
