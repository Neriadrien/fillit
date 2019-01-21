/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:56:08 by hthiessa          #+#    #+#             */
/*   Updated: 2019/01/21 17:57:30 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define MAX_WIDTH 13

# define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
# define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

# define LONG_TO_BINARY_PATTERN BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN
# define LONG_TO_BINARY(long_byte) BYTE_TO_BINARY(long_byte >> 56), BYTE_TO_BINARY(long_byte >> 48), BYTE_TO_BINARY(long_byte >> 40), BYTE_TO_BINARY(long_byte >> 32), BYTE_TO_BINARY(long_byte >> 24), BYTE_TO_BINARY(long_byte >> 16), BYTE_TO_BINARY(long_byte >> 8), BYTE_TO_BINARY(long_byte)

typedef struct	s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct	s_tetritype
{
	t_position	points[4];
	int			height;
	int			width;
	long int	cache[MAX_WIDTH];

}				t_tetritype;
typedef struct	s_tetri
{
	t_tetritype	*type;
	t_position	position;
}				t_tetri;
typedef short int	t_grid[16];


#endif
