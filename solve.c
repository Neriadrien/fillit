/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:54:45 by hthiessa          #+#    #+#             */
/*   Updated: 2019/01/21 17:59:10 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "solve.h"
#include "libft/libft.h"



#include <stdio.h>



int		sqrt_aprox(int nb)
{
	int	i;

	i = 0;
	while (i < 47000)
	{
		if ((i * i) >= nb)
			return (i);
		i++;
	}
	return (i);
}

void	print_grid(char *grid[], int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		ft_putstr(grid[i]);
		i++;
	}
}

void	print_and_exit(t_tetri *tetriminos, int nb_tetri,
					   int actual_width)
{
	char	**printable_grid;
	int		i;
	int		j;

	if (!(printable_grid = malloc(actual_width * sizeof(*printable_grid))))
		exit(1); // TODO free
	i = 0;
	while (i < actual_width)
	{
		if (!(printable_grid[i] = ft_strnew(actual_width + 1)))
			exit (1); // TODO free
		ft_memset(printable_grid[i], '.', actual_width);
		printable_grid[i][actual_width] = '\n';
		i++;
	}
	i = 0;
	while (i < nb_tetri)
	{
		j = 0;
		while (j < 4)
		{
			printable_grid[tetriminos[i].type->points[j].y + tetriminos[i].position.y
				][tetriminos[i].type->points[j].x + tetriminos[i].position.x
					] = 'A' + i;
			j++;
		}
		i++;
	}
	print_grid(printable_grid, actual_width);
	//free
	exit(0);
}

void	solve_and_print(t_tetri *tetriminos, int nb_tetri)
{
	t_grid	grid;
	int		actual_width;

	ft_memset(&grid, 0, sizeof(grid));
	actual_width = sqrt_aprox(nb_tetri * 4);
	while (actual_width <= MAX_WIDTH)
	{
		solve_and_print_rec(0, tetriminos, grid, nb_tetri, actual_width);
		actual_width++;
	}
	ft_putstr_fd("Error, max width of grid reached\n", 2);
	exit(1);
	//TODO Error
}

void	print_tab_short_int(int id, short int*tab)
{
	for (int index = 0; index < 16; index++)
	{
		printf("[%d] %3d|"SHORT_TO_BINARY_PATTERN"\n",
			   id, index, SHORT_TO_BINARY(tab[index]));
	}
}

void	solve_and_print_rec(int index, t_tetri *tetriminos, t_grid grid,
							int nb_tetri, int actual_width)
{
	t_tetri		*tetri;
	long int	*grid_for_cmp;
	long int	tetri_actual;
	int			bool_same_type;

	if (index == nb_tetri)
		print_and_exit(tetriminos, nb_tetri, actual_width);
	tetri = &tetriminos[index];
	tetri->position.y = 0;
	int max_y = actual_width - tetri->type->height;
	int max_x = actual_width - tetri->type->width;
	grid_for_cmp = (long*)grid;
	if (tetri->type->last_position)
	{
		tetri->position.y = tetri->type->last_position->y;
		tetri->position.x = tetri->type->last_position->x + 1;
		grid_for_cmp = (long*)((short int*)grid_for_cmp + tetri->position.y);;
		bool_same_type = 1;
	}
	else
		bool_same_type = 0;
	while (tetri->position.y <= max_y)
	{
		tetri_actual = tetri->type->mask;
		if (!bool_same_type)
			tetri->position.x = 0;
		else
		{
			tetri_actual >>= tetri->position.x;
			bool_same_type = 0;
		}
		while (tetri->position.x <= max_x)
		{
			if ((*grid_for_cmp & tetri_actual) == 0)
			{
				*grid_for_cmp ^= tetri_actual;
				tetri->type->last_position = &tetri->position;
				solve_and_print_rec(index + 1, tetriminos, grid, nb_tetri, actual_width);
				*grid_for_cmp ^= tetri_actual;
			}
			tetri_actual >>= 1;
			tetri->position.x++;
		}
		grid_for_cmp = (long*)((short int*)grid_for_cmp + 1);
		tetri->position.y++;
	}
	tetri->type->last_position = NULL;
}
