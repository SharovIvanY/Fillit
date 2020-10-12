/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:24:29 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/02 12:41:15 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!str)
		return (NULL);
	ft_strcpy(str, src);
	return (str);
}
