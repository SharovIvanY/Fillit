/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defence.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:48:20 by jbashiri          #+#    #+#             */
/*   Updated: 2019/03/07 11:21:31 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_validate(int x, int y, char **tetris, int tetrimino_stack)
{
	int	flag;

	y = 0;
	flag = 0;
	while (x < tetrimino_stack && tetris[x][y])
	{
		if (tetris[x][y] == '#')
		{
			if (y - 5 >= 0 && tetris[x][y - 5] == '#')
				flag++;
			if (y + 5 <= 19 && tetris[x][y + 5] == '#')
				flag++;
			if (y - 1 >= 0 && tetris[x][y - 1] == '#')
				flag++;
			if (y + 1 <= 19 && tetris[x][y + 1] == '#')
				flag++;
		}
		y++;
	}
	return (flag);
}

int		tetrimino_validate(char **tetris, int tetrimino_stack)
{
	int	x;
	int	y;
	int	flag;

	x = 0;
	y = 0;
	while (x < tetrimino_stack && tetris[x])
	{
		flag = check_validate(x, y, tetris, tetrimino_stack);
		if (flag != 6 && flag != 8)
			return (106);
		else if (flag == 8)
			y = 0;
		x++;
	}
	return (0);
}

int		char_validate(char **tetris, int tetrimino_stack)
{
	int	x;
	int	y;

	x = 0;
	while (x < tetrimino_stack)
	{
		y = 0;
		while (tetris[x][y])
		{
			if (y == 4 || y == 9 || y == 14 || y == 19)
			{
				if (tetris[x][y] != '\n')
					return (104);
			}
			else if (tetris[x][y] != '#' && tetris[x][y] != '.')
				return (105);
			y++;
		}
		x++;
	}
	return (0);
}

int		ft_sizemap_validate(char **tetris, int tetrimino_stack)
{
	int	x;
	int	y;
	int	flag_ns;
	int	flag_hashtag;

	x = 0;
	while (x <= tetrimino_stack - 1)
	{
		y = 0;
		flag_ns = 0;
		flag_hashtag = 0;
		while (y < 20)
		{
			if (tetris[x][y] == '\n')
				flag_ns++;
			if (tetris[x][y] == '#')
				flag_hashtag++;
			y++;
		}
		if (flag_ns != 4 || flag_hashtag != 4)
			return (101);
		x++;
	}
	return (0);
}

int		defence(char **tetris, int tetrimino_stack)
{
	int	error;

	if (tetrimino_stack > 26)
		return (108);
	error = ft_sizemap_validate(tetris, tetrimino_stack);
	RETURN(error);
	error = char_validate(tetris, tetrimino_stack);
	RETURN(error);
	error = tetrimino_validate(tetris, tetrimino_stack);
	RETURN(error);
	return (error);
}
