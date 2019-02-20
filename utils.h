/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:56:08 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/20 19:00:06 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define MAX_WIDTH 13
# define MAX_TETRI 26

typedef unsigned short	t_grid[16];

typedef struct			s_position
{
	int	x;
	int	y;
}						t_position;

typedef t_position		t_points[4];

typedef struct			s_type
{
	t_points		points;
	int				height;
	int				width;
	unsigned long	mask;
	t_position		*last_position;
}						t_type;

typedef struct			s_tetri
{
	t_type		*type;
	t_position	pos;
}						t_tetri;

#endif
