/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_rename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:06:16 by jbashiri          #+#    #+#             */
/*   Updated: 2019/01/27 13:30:47 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		x_plus(int ***tetrimino, int map_size)
{
	tetrimino[0][7][1]++;
	if (tetrimino[0][7][1] > map_size)
	{
		tetrimino[0][7][1] = 0;
		tetrimino[0][7][0]++;
	}
	if (tetrimino[0][7][0] > map_size)
		return (100);
	return (1);
}

int		mapgenint(char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y][x] != 0)
		x++;
	return (x);
}

void	print_map(char **red_push, int map_size)
{
	int y;

	y = 0;
	while (y < map_size)
	{
		ft_putstr(red_push[y]);
		ft_putchar('\n');
		y++;
	}
}

int		training_two(int tetrimino_stack)
{
	int cube_start;
	int map_size;

	cube_start = 1;
	map_size = 1;
	tetrimino_stack = tetrimino_stack * 4;
	while (tetrimino_stack > map_size)
	{
		cube_start++;
		map_size = cube_start * cube_start;
	}
	return (cube_start);
}
