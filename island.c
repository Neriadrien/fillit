/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:03:45 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/20 16:07:31 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "solve.h"
#include "libft/libft.h"

int		island(int x, int y, t_solve_data *data, t_grid visited_cells)
{
	int					nb_empty_cells;
	static t_position	offsets[4] = {{.x = -1, .y = 0}, {.x = 1, .y = 0},
										{.x = 0, .y = -1}, {.x = 0, .y = 1}};
	int					direction;

	if (x < 0 || x >= data->size || y < 0 || y >= data->size
		|| visited_cells[y] & (1 << x) || data->grid[y] & (1 << x))
		return (0);
	visited_cells[y] ^= 1 << x;
	nb_empty_cells = 1;
	direction = 0;
	while (direction < 4)
	{
		nb_empty_cells += island(x + offsets[direction].x,
								y + offsets[direction].y, data, visited_cells);
		if (nb_empty_cells > 3)
			return (nb_empty_cells);
		direction++;
	}
	return (nb_empty_cells);
}

int		enough_cells(t_tetri *tetri, t_solve_data *data, t_grid dead_cells,
					  t_grid prec_dead_cells)
{
	int		island_size;
	int		point;
	t_grid	p_dead_cells;
	int		prec_nb_dead_cells;

	ft_memcpy(dead_cells, prec_dead_cells, sizeof(t_grid));
	prec_nb_dead_cells = data->nb_dead_cells;
	point = 0;
	while (point < 4)
	{
		ft_memcpy(p_dead_cells, prec_dead_cells, sizeof(t_grid));
		island_size = island(tetri->pos.x + tetri->type->points[point].x,
			tetri->pos.y + tetri->type->points[point].y,
			data, dead_cells);
		if (island_size <= 3)
		{
			prec_nb_dead_cells += island_size;
			if ((data->size * data->size - prec_nb_dead_cells) < data->required_free_cells)
				return (0);
		}
		else
			ft_memcpy(dead_cells, p_dead_cells, sizeof(t_grid));
		++point;
	}
	data->nb_dead_cells = prec_nb_dead_cells;
	return (1);
}

/*
** return ((nb_cells - *dead_cells) >= required_free_cells);
*/
