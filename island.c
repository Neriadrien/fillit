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

int		island(int x, int y, t_solve_data *data, short *visited_cells)
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

int		enougth_cells(int index, t_solve_data *data, int *dead_cells)
{
	int		island_size;
	t_grid	visited_cells;
	int		point;
	int		required_free_cells;

	required_free_cells = (data->nb_tetri - (index + 1)) * 4;
	if (required_free_cells - (index + 1) * 6 > 0)
		return (1);
	ft_memset(visited_cells, 0, sizeof(t_grid));
	point = 0;
	while (point < 4)
	{
		island_size = island(data->ltetri[index].pos.x
							+ data->ltetri[index].type->points[point].x,
							data->ltetri[index].pos.y
							+ data->ltetri[index].type->points[point].y,
							data->grid, data->size, (short *)visited_cells);
		if (island_size <= 3)
		{
			*dead_cells += island_size;
			if ((data->size * data->size - *dead_cells) < required_free_cells)
				return (0);
		}
		point++;
	}
	return (1);
}

/*
** return ((nb_cells - *dead_cells) >= required_free_cells);
*/
