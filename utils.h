/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:56:08 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/04 16:58:06 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define MAX_WIDTH 13

typedef struct	s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct	s_tetritype
{
	t_position	points[4];
	int			height;
	int			width;
	long int	mask;
	t_position	*last_position;
}				t_tetritype;

typedef struct	s_tetri
{
	t_tetritype	*type;
	t_position	pos;
}				t_tetri;

typedef short int	t_grid[16];

#endif
