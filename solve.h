/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:54:32 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/04 16:27:01 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include "utils.h"

typedef struct	s_solve_data
{
	t_tetri	*ltetris;
	t_grid	grid;
	int		nb_tetri;
	int		size;
}				t_solve_data;

void			print_and_exit(t_tetri *tetriminos, int nb_tetri,
								int actual_width);
void			solve_and_print(t_tetri *tetriminos, int nb_tetri);
void			print_tab_short_int(int id, short int*tab);
void			solve_and_print_rec(int index, t_solve_data *data);

#endif
