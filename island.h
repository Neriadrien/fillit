/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:23:05 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/04 16:01:39 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISLAND_H
# define ISLAND_H

# include "utils.h"
# include "solve.h"

int	enough_cells(t_tetri *tetri, t_solve_data *data, t_grid dead_cells,
				 t_grid prec_dead_cells);

#endif
