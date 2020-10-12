/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:22:07 by jbashiri          #+#    #+#             */
/*   Updated: 2019/01/27 13:56:55 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_READ 100
# define RETURN(x) if(x != 0) return (x);
# define ERROR {ft_putstr("error\n"); exit(-1);}

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

int		main(int argc, char **argv);
int		pentagon(int fd);
int		forest_gump(int map_size, char **map);
int		algoritm(int ***tetrimino, int tetrimino_stack);
int		algoritm_start(char **map, int ***tetrimino, int stack_tetrimino,
int map_size);
char	**build_position(char **map, int ***tetrimono, int tetra);
char	**destroy_position(char **map, int ***tetrimino, int tetra,
int map_size);
int		alco_two(char ***map, int ***tetrimino, int **tetra);
int		alco_one(char ***map, int ***tetrimino, int *tetra, int oleg);
int		algoritm_val_position(char **map, int ***tetrimino, int tetra);
int		check_map_segfound(char **map, int ***tetrimino, int tetra);
int		algoritm_search(char **map, int ***tetrimino, int tetra);
char	*stack_create(int fd, ssize_t x);
int		if_stack(char **stack, char *stack_double);
char	**brute_force(int fd, int *tetrimino_stack);
int		defence(char **tetris, int tetrimino_stack);
int		ft_sizemap_validate(char **tetris, int tetrimino_stack);
int		char_validate(char **tetris, int tetrimino_stack);
int		tetrimino_validate(char **tetris, int tetrimino_stack);
int		check_validate(int x, int y, char **tetris, int tetrimino_stack);
int		***tetris_reroll(char **tetris, int tetrimino_stack);
int		tetra_pack_one(int ***tetrimino, int tetra, char **tetris);
int		tetra_pack_two(int ***tetrimino, int tetra);
int		position_to_null(int ***tetrimino, int tetra);
int		position_minus_start(int ***tetrimino, int tetra);
char	**fall_generation(int map_size);
char	**generation(int tetrimino_stack);
int		free_memory_int (int ***map, int len);
int		free_memory_char(char **map, int len);
int		training_two(int tetrimino_stack);
void	print_map(char **red_push, int tetrimino_stack);
int		mapgenint(char **map);
int		x_plus(int ***tetrimino, int map_size);
int		right(int ***tetrimino, int tetra);
int		left(int ***tetrimino, int tetra);
int		tetrimino_length(int ***tetrimino, int tetra);

#endif
