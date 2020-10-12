/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_reroll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:19:02 by jbashiri          #+#    #+#             */
/*   Updated: 2019/01/25 17:13:54 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		position_minus_start(int ***tetrimino, int tetra)
{
	int	x;

	x = 3;
	if (tetrimino[tetra][0][0] == 0 && tetrimino[tetra][0][1] == 0)
		return (0);
	if (tetrimino[tetra][0][0] != 0)
		while (x >= 0)
		{
			tetrimino[tetra][x][0] -= tetrimino[tetra][0][0];
			x--;
		}
	x = 3;
	if (tetrimino[tetra][0][1] != 0)
		while (x >= 0)
		{
			tetrimino[tetra][x][1] -= tetrimino[tetra][0][1];
			x--;
		}
	return (1);
}

int		position_to_null(int ***tetrimino, int tetra)
{
	int	min;
	int	x;

	x = 0;
	min = tetrimino[tetra][0][0];
	while (x++ <= 3)
		min = (tetrimino[tetra][x][0] < min ? tetrimino[tetra][x][0] : min);
	x = 0;
	if (min > 0)
		while (x <= 3)
			tetrimino[tetra][x++][0] -= min;
	x = 0;
	min = tetrimino[tetra][0][1];
	while (x++ < 3)
		min = (tetrimino[tetra][x][1] < min ? tetrimino[tetra][x][1] : min);
	x = 0;
	if (min > 0)
		while (x <= 3)
			tetrimino[tetra][x++][0] -= min;
	position_minus_start(tetrimino, tetra);
	return (0);
}

int		tetra_pack_two(int ***tetrimino, int tetra)
{
	tetrimino[tetra][4] = (int*)malloc(sizeof(int) * 2);
	tetrimino[tetra][4][0] = tetra;
	tetrimino[tetra][4][1] = tetra;
	tetrimino[tetra][5] = (int*)malloc(sizeof(int));
	tetrimino[tetra][5][0] = tetra;
	tetrimino[tetra][6] = (int*)malloc(sizeof(int) * 3);
	tetrimino[tetra][6][0] = tetrimino_length(tetrimino, tetra);
	tetrimino[tetra][6][1] = left(tetrimino, tetra);
	tetrimino[tetra][6][2] = right(tetrimino, tetra);
	tetrimino[tetra][7] = (int*)malloc(sizeof(int) * 4);
	tetrimino[tetra][7][0] = 0;
	tetrimino[tetra][7][1] = 0;
	tetrimino[tetra][7][2] = 0;
	tetrimino[tetra][7][3] = 0;
	return (0);
}

int		tetra_pack_one(int ***tetrimino, int tetra, char **tetris)
{
	int	x;
	int	tetra_y;

	x = 0;
	tetra_y = 0;
	while (x < 19)
	{
		if (tetris[tetra][x] == '#')
		{
			tetrimino[tetra][tetra_y] = (int*)malloc(sizeof(int) * 2);
			tetrimino[tetra][tetra_y][1] = (x % 5);
			tetrimino[tetra][tetra_y][0] = (x / 5);
			if (tetra_y == 3)
			{
				tetra_pack_two(tetrimino, tetra);
				if (tetrimino[tetra][0][0] != 0 || tetrimino[tetra][0][1] != 0)
					position_to_null(tetrimino, tetra);
				break ;
			}
			tetra_y++;
		}
		x++;
	}
	return (0);
}

int		***tetris_reroll(char **tetris, int tetrimino_stack)
{
	int	tetra;
	int	***tetrimino;

	tetra = 0;
	tetrimino = (int***)malloc(sizeof(int**) * tetrimino_stack);
	while (tetra < tetrimino_stack)
	{
		tetrimino[tetra] = (int**)malloc(sizeof(int*) * 8);
		tetra_pack_one(tetrimino, tetra, tetris);
		tetra++;
	}
	return (tetrimino);
}
