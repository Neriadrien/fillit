/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:54:45 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/04 16:19:04 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "solve.h"
#include "utils.h"
#include "libft.h"
#include "print.h"

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

void	solve_and_print(t_tetri *tetriminos, int nb_tetri)
{
	t_grid	grid;
	int		actual_width;

	ft_memset(&grid, 0, sizeof(grid));
	actual_width = sqrt_aprox(nb_tetri * 4);
	while (actual_width <= MAX_WIDTH)
	{
		solve_and_print_rec(0, (t_solve_data){.tetriminos = tetriminos,
					.grid = &grid, .nb_tetri = nb_tetri,
					.actual_width = actual_width});
		actual_width++;
	}
	ft_putstr_fd("Error, max width of grid reached\n", 2);
	exit(1);
	//TODO Error
}

void	start_position(t_tetri *tetri, t_grid grid, long int **grid_for_cmp,
						long int *tetri_actual)
{
	if (tetri->type->last_position)
	{
		tetri->position.y = tetri->type->last_position->y;
		tetri->position.x = tetri->type->last_position->x + 1;
		*tetri_actual = tetri->type->mask >> tetri->position.x;
		*grid_for_cmp = (long*)(&grid[tetri->position.y]);
	}
	else
	{
		tetri->position.y = 0;
		tetri->position.x = 0;
		*tetri_actual = tetri->type->mask;
		*grid_for_cmp = (long*)grid;
	}
}

void	solve_and_print_rec(int index, t_solve_data data)
{
	t_tetri		*tetri;
	long int	*grid_for_cmp;
	long int	tetri_actual;

	if (index == data.nb_tetri)
		print_and_exit(data.tetriminos, data.nb_tetri, data.actual_width);
	tetri = &data.tetriminos[index];
	start_position(tetri, *data.grid, &grid_for_cmp, &tetri_actual);
	while (tetri->position.y <= data.actual_width - tetri->type->height)
	{
		while (tetri->position.x <= data.actual_width - tetri->type->width)
		{
			if ((*grid_for_cmp & tetri_actual) == 0)
			{
				*grid_for_cmp ^= tetri_actual;
				tetri->type->last_position = &tetri->position;
				solve_and_print_rec(index + 1, data);
				*grid_for_cmp ^= tetri_actual;
			}
			tetri_actual >>= 1;
			tetri->position.x++;
		}
		tetri_actual = tetri->type->mask;
		tetri->position.x = 0;
		grid_for_cmp = (long*)(&(*data.grid)[++tetri->position.y]);
	}
	tetri->type->last_position = NULL;
}
