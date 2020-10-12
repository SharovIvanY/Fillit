/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:21:44 by jbashiri          #+#    #+#             */
/*   Updated: 2019/03/01 15:35:10 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			pentagon(int fd)
{
	int		error;
	char	**tetris;
	int		***tetrimino;
	int		tetrimino_stack;

	tetrimino_stack = 0;
	error = 0;
	tetris = brute_force(fd, &tetrimino_stack);
	RETURN(error);
	if (tetrimino_stack == 0)
		return (1001);
	error = defence(tetris, tetrimino_stack);
	RETURN(error);
	tetrimino = tetris_reroll(tetris, tetrimino_stack);
	error = algoritm(tetrimino, tetrimino_stack);
	free_memory_char(tetris, tetrimino_stack);
	free_memory_int(tetrimino, tetrimino_stack);
	return (error);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		error;

	error = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error = 100000;
	if (error == 0)
		error = pentagon(fd);
	if (error != 0)
		ft_putstr("error\n");
	close(fd);
	return (0);
}
