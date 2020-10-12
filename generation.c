/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 23:07:38 by jbashiri          #+#    #+#             */
/*   Updated: 2019/01/25 17:11:56 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**fall_generation(int map_size)
{
	int		x;
	int		y;
	char	**map;

	map = (char**)malloc(sizeof(char*) * map_size + 1);
	x = 0;
	while (x < map_size)
	{
		y = 0;
		map[x] = ft_strnew((size_t)map_size + 1);
		while (y < map_size)
		{
			map[x][y] = '.';
			y++;
		}
		x++;
	}
	return (map);
}

char		**generation(int stack_tetrimino)
{
	int		map_size;
	int		x;
	int		y;
	char	**map;

	map_size = training_two(stack_tetrimino);
	map = (char**)malloc(sizeof(char*) * map_size + 1);
	x = 0;
	while (x < map_size)
	{
		y = 0;
		map[x] = ft_strnew((size_t)map_size + 1);
		while (y < map_size)
		{
			map[x][y] = '.';
			y++;
		}
		x++;
	}
	return (map);
}
