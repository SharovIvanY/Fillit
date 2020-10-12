/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:24:36 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/15 17:16:44 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*xcom;

	if (!(xcom = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	else if (content == NULL)
	{
		xcom->content = NULL;
		xcom->content_size = 0;
	}
	else
	{
		xcom->content = (char*)content;
		xcom->content_size = content_size;
	}
	xcom->next = NULL;
	return (xcom);
}
