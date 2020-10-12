/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:26:22 by jbashiri          #+#    #+#             */
/*   Updated: 2019/03/01 15:34:57 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		free_memory_char(char **map, int len)
{
	int x;

	x = 0;
	while (x < len)
	{
		free(map[x]);
		x++;
	}
	free(map);
	return (1);
}

int		free_memory_int(int ***map, int len)
{
	int y;
	int tetra;

	tetra = 0;
	while (tetra < len)
	{
		y = 0;
		while (y < 8)
		{
			free(map[tetra][y]);
			y++;
		}
		free(map[tetra]);
		tetra++;
	}
	free(map);
	return (1);
}
