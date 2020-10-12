/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:26:50 by jbashiri          #+#    #+#             */
/*   Updated: 2019/01/27 13:32:32 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			algoritm_search(char **map, int ***tetrimino, int tetra)
{
	int		map_size;

	map_size = tetrimino[0][5][0];
	while (tetrimino[0][7][1] < map_size && tetrimino[0][7][0] < map_size)
	{
		if ((tetrimino[tetra][6][0] + tetrimino[0][7][0]) < map_size &&
(tetrimino[0][7][1] - tetrimino[tetra][6][1]) >= 0 &&
(tetrimino[tetra][6][2] + tetrimino[0][7][1]) < map_size)
			if (map[tetrimino[0][7][0]][tetrimino[0][7][1]] == '.')
				return (1);
		if (x_plus(tetrimino, map_size - 1) == 100)
			return (100);
	}
	return (100);
}

int			check_map_segfound(char **map, int ***tetrimino, int tetra)
{
	int		len;
	int		flag;

	flag = 0;
	if (map[tetrimino[0][7][0]][tetrimino[0][7][1]] == '.')
		flag++;
	len = 0;
	while (++len <= 3)
	{
		if (map[tetrimino[tetra][len][0] + tetrimino[0][7][0]]
[tetrimino[tetra][len][1] + tetrimino[0][7][1]] == '.')
			flag++;
	}
	return (flag);
}

int			algoritm_val_position(char **map, int ***tetrimino, int tetra)
{
	int		max_size;
	int		x;
	int		y;

	x = tetrimino[0][7][1];
	y = tetrimino[0][7][0];
	max_size = tetrimino[0][5][0];
	if (tetrimino[tetra][6][0] + y >= max_size)
		return (0);
	if (x - tetrimino[tetra][6][1] < 0)
		return (0);
	if (tetrimino[tetra][6][2] + x >= max_size)
		return (0);
	if (check_map_segfound(map, tetrimino, tetra) == 4)
		return (1);
	return (0);
}

char		**build_position(char **map, int ***tetrimino, int tetra)
{
	char	ch;
	int		x;
	int		y;

	x = tetrimino[0][7][1];
	y = tetrimino[0][7][0];
	ch = 65 + tetrimino[tetra][4][0];
	map[y][x] = ch;
	map[tetrimino[tetra][1][0] + y][tetrimino[tetra][1][1] + x] = ch;
	map[tetrimino[tetra][2][0] + y][tetrimino[tetra][2][1] + x] = ch;
	map[tetrimino[tetra][3][0] + y][tetrimino[tetra][3][1] + x] = ch;
	return (map);
}

char		**destroy_position(char **map, int ***tetrimino, int tetra,
int map_size)
{
	int		y;
	int		x;

	y = tetrimino[tetra][7][2];
	x = tetrimino[tetra][7][3];
	map[y][x] = '.';
	map[tetrimino[tetra][1][0] + y][tetrimino[tetra][1][1] + x] = '.';
	map[tetrimino[tetra][2][0] + y][tetrimino[tetra][2][1] + x] = '.';
	map[tetrimino[tetra][3][0] + y][tetrimino[tetra][3][1] + x] = '.';
	tetrimino[0][7][0] = y;
	tetrimino[0][7][1] = x;
	x_plus(tetrimino, map_size - 1);
	return (map);
}
