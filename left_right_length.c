/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:13:07 by amace-ty          #+#    #+#             */
/*   Updated: 2019/01/25 17:13:11 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetrimino_length(int ***tetrimino, int tetra)
{
	int	max;
	int	min;

	max = tetrimino[tetra][0][0];
	min = tetrimino[tetra][0][0];
	if (tetrimino[tetra][1][0] > max)
		max = tetrimino[tetra][1][0];
	if (tetrimino[tetra][2][0] > max)
		max = tetrimino[tetra][2][0];
	if (tetrimino[tetra][3][0] > max)
		max = tetrimino[tetra][3][0];
	if (tetrimino[tetra][1][0] < min)
		min = tetrimino[tetra][1][0];
	if (tetrimino[tetra][2][0] < min)
		min = tetrimino[tetra][2][0];
	if (tetrimino[tetra][3][0] < min)
		min = tetrimino[tetra][3][0];
	return (max - min);
}

int		left(int ***tetrimino, int tetra)
{
	int	max;
	int	min;

	min = tetrimino[tetra][0][1];
	max = tetrimino[tetra][0][1];
	if (tetrimino[tetra][1][1] < min)
		min = tetrimino[tetra][1][1];
	if (tetrimino[tetra][2][1] < min)
		min = tetrimino[tetra][2][1];
	if (tetrimino[tetra][3][1] < min)
		min = tetrimino[tetra][3][1];
	return (max - min);
}

int		right(int ***tetrimino, int tetra)
{
	int	max;
	int	min;

	min = tetrimino[tetra][0][1];
	max = tetrimino[tetra][0][1];
	if (tetrimino[tetra][1][1] > max)
		max = tetrimino[tetra][1][1];
	if (tetrimino[tetra][2][1] > max)
		max = tetrimino[tetra][2][1];
	if (tetrimino[tetra][3][1] > max)
		max = tetrimino[tetra][3][1];
	return (max - min);
}
