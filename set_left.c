/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:36:28 by hbode             #+#    #+#             */
/*   Updated: 2019/02/04 19:37:05 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		set_tetri_left(t_points *grid, int i)
{
	int		j;
	int		minx;
	int		miny;

	j = 0;
	minx = 3;
	miny = 3;
	while (j < 4)
	{
		if (grid[i][j].x < minx)
			minx = grid[i][j].x;
		if (grid[i][j].y < miny)
			miny = grid[i][j].y;
		j++;
	}
	j = 0;
	while (j < 4)
	{
		grid[i][j].x -= minx;
		grid[i][j].y -= miny;
		j++;
	}
}

void			set_all_left(t_points *grid, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		set_tetri_left(grid, i);
		i++;
	}
}
