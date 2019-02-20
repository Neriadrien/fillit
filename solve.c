/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:54:45 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/20 16:50:54 by hthiessa         ###   ########.fr       */
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
		solve_and_print_rec(0, &data);
		data.size++;
	}
	ft_putstr_fd("Error, max width of grid reached\n", 2);
	exit(1);
}

/*
** TODO Error apres le exit
*/

void	start_position(t_tetri *tetri, t_grid grid, unsigned long int **grid_for_cmp,
						unsigned long int *tetri_actual)
{
	if (tetri->type->last_position)
	{
		tetri->pos.y = tetri->type->last_position->y;
		tetri->pos.x = tetri->type->last_position->x + 1;
		*tetri_actual = (unsigned long)tetri->type->mask >> tetri->pos.x;
		*grid_for_cmp = (unsigned long*)(&grid[tetri->pos.y]);
	}
	else
	{
		tetri->pos.y = 0;
		tetri->pos.x = 0;
		*tetri_actual = tetri->type->mask;
		*grid_for_cmp = (unsigned long*)grid;
	}
}

void	solve_and_print_rec(int index, t_solve_data *p)
{
	unsigned long int	*grid_for_cmp;
	unsigned long int	tetri_actual;

	if (index == p->nb_tetri)
		print_and_exit(p);
	start_position(&p->ltetri[index], p->grid, &grid_for_cmp, &tetri_actual);
	while (p->ltetri[index].pos.y <= p->size - p->ltetri[index].type->height)
	{
		while (p->ltetri[index].pos.x <= p->size - p->ltetri[index].type->width)
		{
			if ((*grid_for_cmp & tetri_actual) == 0)
			{
				*grid_for_cmp ^= tetri_actual;
				p->ltetri[index].type->last_position = &p->ltetri[index].pos;
				solve_and_print_rec(index + 1, p);
				*grid_for_cmp ^= tetri_actual;
			}
			tetri_actual = (unsigned long)tetri_actual >> 1;
			p->ltetri[index].pos.x++;
		}
		tetri_actual = p->ltetri[index].type->mask;
		p->ltetri[index].pos.x = 0;
		grid_for_cmp = (unsigned long*)(&p->grid[++p->ltetri[index].pos.y]);
	}
	p->ltetri[index].type->last_position = NULL;
}
