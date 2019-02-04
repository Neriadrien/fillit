/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:23:05 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/04 15:23:30 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		island(int x, int y, short *grid,
			   int actual_width, short *visited_cells);
int		enougth_cells(int index, t_tetri *tetri, short *grid,
					  int nb_tetri, int actual_width, int *dead_cells);
