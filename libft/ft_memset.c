/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:04:48 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/01 18:13:33 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, size_t len)
{
	unsigned char	*massive;
	size_t			x;

	massive = (unsigned char*)str;
	x = 0;
	while (x < len)
		massive[x++] = ch;
	return (str);
}
