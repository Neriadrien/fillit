/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:54:45 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/20 18:11:18 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "solve.h"
#include "utils.h"
#include "libft/libft.h"
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
	t_solve_data	data;

	ft_memset(&data.grid, 0, sizeof(data.grid));
	data.size = sqrt_aprox(nb_tetri * 4);
	data.ltetri = tetriminos;
	data.nb_tetri = nb_tetri;
	while (data.size <= MAX_WIDTH)
	{
		solve_and_print_rec(0, &data.ltetri[0], data.ltetri[0].type, &data);
		data.size++;
	}
	ft_putstr_fd("Error, max width of grid reached\n", 2);
	exit(1);
}

/*
** TODO Error apres le exit
*/

void	start_position(t_position *pos, t_tetri *tetri, t_grid grid, unsigned long int **grid_for_cmp,
						unsigned long int *tetri_actual)
{
	if (tetri->type->last_position)
	{
		pos->y = tetri->type->last_position->y;
		pos->x = tetri->type->last_position->x + 1;
		*tetri_actual = (unsigned long)tetri->type->mask >> pos->x;
		*grid_for_cmp = (unsigned long*)(&grid[pos->y]);
	}
	else
	{
		pos->y = 0;
		pos->x = 0;
		*tetri_actual = tetri->type->mask;
		*grid_for_cmp = (unsigned long*)grid;
	}
}

void	solve_and_print_rec(int index, t_tetri *tetri, t_type *type,
							t_solve_data *p)
{
	unsigned long	*grid_for_cmp;
	unsigned long	tetri_actual;
	t_position		pos;
	int				size;
	int				height;
	int				width;
	unsigned long	mask;

	if (index == p->nb_tetri)
		print_and_exit(p);
	size = p->size;
	height = type->height;
	width = type->width;
	mask = type->mask;
	start_position(&pos, tetri, p->grid, &grid_for_cmp, &tetri_actual);
	while (pos.y <= size - height)
	{
		while (pos.x <= size - width)
		{
			if ((*grid_for_cmp & tetri_actual) == 0)
			{
				*grid_for_cmp ^= tetri_actual;
				type->last_position = &pos;
				tetri->pos = pos;
				solve_and_print_rec(index + 1, &p->ltetri[index + 1],
									p->ltetri[index + 1].type, p);
				*grid_for_cmp ^= tetri_actual;
			}
			tetri_actual = (unsigned long)tetri_actual >> 1;
			pos.x++;
		}
		tetri_actual = mask;
		pos.x = 0;
		grid_for_cmp = (unsigned long*)(&p->grid[++pos.y]);
	}
	type->last_position = NULL;
}
