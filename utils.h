/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:56:08 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/18 19:03:05 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define MAX_WIDTH 13
# define MAX_TETRI 26

typedef struct	s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct	s_type
{
	t_position	points[4];
	int			height;
	int			width;
	long int	mask;
	t_position	*last_position;
}				t_type;

typedef struct	s_tetri
{
	t_type		*type;
	t_position	pos;
}				t_tetri;

typedef t_position	t_points[4];
typedef short int	t_grid[16];

#endif
