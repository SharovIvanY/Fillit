/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:14:17 by jbashiri          #+#    #+#             */
/*   Updated: 2019/03/04 15:42:59 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			forest_gump(int map_size, char **map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map_size)
	{
		x = 0;
		while (x < map_size)
		{
			if (map[y][x] == '.')
				if (y > map_size + 1)
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int			alco_two(char ***map, int ***tetrimino, int **tetra)
{
	int		oleg;
	int		map_size;

	map_size = tetrimino[0][5][0];
	if ((oleg = algoritm_search(*map, tetrimino, **tetra - 1)) > 0)
	{
		if (algoritm_val_position(*map, tetrimino, **tetra - 1))
		{
			tetrimino[**tetra - 1][7][2] = tetrimino[0][7][0];
			tetrimino[**tetra - 1][7][3] = tetrimino[0][7][1];
			*map = build_position(*map, tetrimino, **tetra - 1);
			return (1000);
		}
		oleg = x_plus(tetrimino, map_size - 1);
	}
	return (oleg);
}

int			alco_one(char ***map, int ***tetrimino, int *tetra, int oleg)
{
	int		map_size;
	int		stack_tetrimino;

	oleg = alco_two(&*map, tetrimino, &tetra);
	stack_tetrimino = tetrimino[0][4][1];
	map_size = tetrimino[0][5][0];
	if (oleg == 1000)
		return (666);
	if (oleg == 100 && *tetra == 1)
		return (0);
	if (oleg == 100 && *tetra != 1)
	{
		if (*tetra == stack_tetrimino)
			if (forest_gump(map_size, *map))
				return (0);
		*map = destroy_position(*map, tetrimino, *tetra - 2, map_size);
		*tetra = (*tetra > 1 ? *tetra - 1 : *tetra);
		return (777);
	}
	return (oleg);
}

int			algoritm_start(char **map, int ***tetrimino,
				int stack_tetrimino, int map_size)
{
	int		tetra;
	int		oleg;

	tetra = 1;
	while (tetra <= stack_tetrimino)
	{
		if (tetrimino[tetra - 1][6][0] + 1 > map_size)
			return (0);
		while (1)
		{
			oleg = alco_one(&map, tetrimino, &tetra, stack_tetrimino);
			if (oleg == 666)
				break ;
			if (oleg == 777)
				continue;
			if (oleg != 1)
				return (0);
		}
		tetra++;
		tetrimino[0][7][0] = 0;
		tetrimino[0][7][1] = 0;
	}
	return (1);
}

int			algoritm(int ***tetrimino, int tetrimino_stack)
{
	int		flag;
	char	**map;
	int		map_size;

	flag = 0;
	map = generation(tetrimino_stack);
	map_size = mapgenint(map);
	tetrimino[0][4][1] = tetrimino_stack;
	while (flag == 0)
	{
		tetrimino[0][7][0] = 0;
		tetrimino[0][7][1] = 0;
		tetrimino[0][5][0] = map_size;
		flag = algoritm_start(map, tetrimino, tetrimino_stack, map_size);
		if (flag == 0)
		{
			free_memory_char(map, map_size);
			map_size++;
			map = fall_generation(map_size);
		}
	}
	print_map(map, map_size);
	free_memory_char(map, map_size);
	return (0);
}
