/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:54:45 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/20 19:16:25 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "island.h"
#include "solve.h"
#include "utils.h"
#include "libft/libft.h"
#include "print.h"

int		sqrt_aprox(int nb)
{
	int	i;

	i = 1;
	while (i < nb / i)
		++i;
	return (i);
}

void	solve_set_values(t_tetri *tetri, t_type *type, t_solve_data *p,
			t_solve_local_data *d)
{
	if (type->last_position.x != 0
		|| type->last_position.y != 0)
	{
		tetri->pos.y = type->last_position.y;
		tetri->pos.x = type->last_position.x + 1;
		d->tetri_actual = (unsigned long)type->mask >> tetri->pos.x;
		d->grid_for_cmp = (unsigned long*)&p->grid[tetri->pos.y];
	}
	else
	{
		tetri->pos.y = 0;
		tetri->pos.x = 0;
		d->tetri_actual = type->mask;
		d->grid_for_cmp = (unsigned long*)p->grid;
	}
	d->prec_last_pos = type->last_position;
	d->max_height = p->size - type->height;
	d->max_width = p->size - type->width;
	p->required_free_cells -= 4;
	d->nb_dead_cells = p->nb_dead_cells;
}

void	solve_and_print_rec(int index, t_tetri *tetri, t_solve_data *p,
							t_grid prec_dead_cells)
{
	t_solve_local_data d;

	if (index == p->nb_tetri)
		print_and_exit(p);
	solve_set_values(tetri, tetri->type, p, &d);
	while (tetri->pos.y <= d.max_height)
	{
		while (tetri->pos.x <= d.max_width)
		{
			if (!(*d.grid_for_cmp & d.tetri_actual))// && enough_cells(tetri, p, d.dead_cells, prec_dead_cells))
			{
				*d.grid_for_cmp ^= d.tetri_actual;
				tetri->type->last_position = tetri->pos;
				solve_and_print_rec(index + 1, &p->ltetri[index + 1], p,
									d.dead_cells);
				*d.grid_for_cmp ^= d.tetri_actual;
			}
			d.tetri_actual = (unsigned long)d.tetri_actual >> 1;
			++tetri->pos.x;
		}
		d.tetri_actual = tetri->type->mask;
		tetri->pos.x = 0;
		d.grid_for_cmp = (unsigned long*)(&p->grid[++tetri->pos.y]);
	}
	tetri->type->last_position = d.prec_last_pos;
	p->required_free_cells += 4;
	p->nb_dead_cells = d.nb_dead_cells;
}

void	solve_and_print(t_tetri *tetriminos, int nb_tetri)
{
	t_solve_data	data;
	t_grid			dead_cells;

	ft_memset(&data.grid, 0, sizeof(data.grid));
	data.size = sqrt_aprox(nb_tetri * 4);
	data.ltetri = tetriminos;
	data.nb_tetri = nb_tetri;
	data.required_free_cells = nb_tetri * 4;
	data.nb_dead_cells = 0;
	ft_bzero(dead_cells, sizeof(t_grid));
	while (data.size <= MAX_WIDTH)
	{
		solve_and_print_rec(0, &data.ltetri[0], &data, dead_cells);
		++data.size;
	}
	ft_putstr_fd("Error, max width of grid reached\n", 2);
	exit(1);
}

/*
** TODO Error apres le exit
*/
