/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defence.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 13:33:21 by jbashiri          #+#    #+#             */
/*   Updated: 2019/01/27 13:08:15 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*stack_create(int fd, ssize_t x)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*allstr;

	str = ft_strnew(BUFF_READ);
	allstr = ft_strnew(1);
	while ((x = read(fd, str, BUFF_READ)) > 0)
	{
		str2 = ft_strncpy(ft_strnew((size_t)x), str, (size_t)x);
		str3 = allstr;
		allstr = ft_strjoin(str3, str2);
		free(str2);
		free(str3);
	}
	free(str);
	return (allstr);
}

int			if_stack(char **stack, char *stack_double)
{
	if (*stack)
	{
		if (ft_strlen(*stack) > 20)
		{
			stack_double = *stack;
			*stack = ft_strsub(stack_double, 1,
					(size_t)(ft_strlen(stack_double) - 1));
			free(stack_double);
		}
		else if (ft_strlen(*stack) == 0)
			return (1);
		else
			ERROR;
	}
	return (0);
}

char		**brute_force(int fd, int *x)
{
	char	*stack;
	char	*stack_double;
	char	**tetrimino;
	ssize_t num;

	num = 0;
	stack = stack_create(fd, num);
	tetrimino = (char**)malloc(sizeof(char*) * 26);
	while (stack != NULL && ft_strlen(stack) > 0)
	{
		tetrimino[*x] = ft_strncpy(ft_strnew(21), stack, 20);
		if (ft_strlen(tetrimino[*x]) != 20)
			ERROR;
		*x += 1;
		stack_double = stack;
		stack = ft_strsub(stack_double, 20,
				(size_t)(ft_strlen(stack_double) - 20));
		free(stack_double);
		if (if_stack(&stack, stack_double) == 1)
			break ;
	}
	if (ft_strlen(stack) > 0)
		ERROR;
	free(stack);
	return (tetrimino);
}
