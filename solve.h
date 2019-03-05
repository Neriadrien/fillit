/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:54:32 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/20 17:32:08 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include "utils.h"

typedef struct	s_solve_data
{
	t_tetri	*ltetri;
	t_grid	grid;
	int		nb_tetri;
	int		size;
}				t_solve_data;

typedef struct	s_solve_local_data
{
	unsigned long	*grid_for_cmp;
	unsigned long	tetri_actual;
	int				max_height;
	int				max_width;
	int				max_width_last;
	t_position		prec_last_pos;
}				t_solve_local_data;

void			solve_and_print(t_tetri *tetriminos, int nb_tetri);

#endif
