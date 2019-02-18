/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:57:31 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/18 17:25:14 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "solve.h"

int		max(int first, int second)
{
	return (first > second ? first : second);
}

void	generate_type_values(t_type *type)
{
	int point;

	type->mask = 0;
	type->height = 0;
	type->width = 0;
	type->last_position = NULL;
	point = 0;
	while (point < 4)
	{
		type->height = max(type->height, type->points[point].y + 1);
		type->width = max(type->width, type->points[point].x + 1);
		((short int*)&type->mask)[type->points[point].y] ^=
			1 << (sizeof(short int) * 8 - 1 - type->points[point].x);
		point++;
	}
}

#include <stdlib.h>

void	parse_file(char *filename, int *nb_tetri, t_position **positions)
{
	int index;

	index = 0;
	while (index < MAX_TETRI)
	{
		if (!(positions[index] = ft_memalloc(4 * sizeof(t_position))))
			exit(1);
		index++;
	}
	*nb_tetri = ft_atoi(filename);
	positions[0][0] = (t_position){.x = 1, .y = 0};
	positions[0][1] = (t_position){.x = 2, .y = 0};
	positions[0][2] = (t_position){.x = 0, .y = 1};
	positions[0][3] = (t_position){.x = 1, .y = 1};
	positions[1][0] = (t_position){.x = 0, .y = 0};
	positions[1][1] = (t_position){.x = 1, .y = 0};
	positions[1][2] = (t_position){.x = 1, .y = 1};
	positions[1][3] = (t_position){.x = 1, .y = 2};
	positions[2][0] = (t_position){.x = 1, .y = 0};
	positions[2][1] = (t_position){.x = 2, .y = 0};
	positions[2][2] = (t_position){.x = 0, .y = 1};
	positions[2][3] = (t_position){.x = 1, .y = 1};
	positions[3][0] = (t_position){.x = 1, .y = 0};
	positions[3][1] = (t_position){.x = 2, .y = 0};
	positions[3][2] = (t_position){.x = 0, .y = 1};
	positions[3][3] = (t_position){.x = 1, .y = 1};
	positions[4][0] = (t_position){.x = 1, .y = 0};
	positions[4][1] = (t_position){.x = 2, .y = 0};
	positions[4][2] = (t_position){.x = 0, .y = 1};
	positions[4][3] = (t_position){.x = 1, .y = 1};
	positions[5][0] = (t_position){.x = 1, .y = 0};
	positions[5][1] = (t_position){.x = 2, .y = 0};
	positions[5][2] = (t_position){.x = 0, .y = 1};
	positions[5][3] = (t_position){.x = 1, .y = 1};
	positions[6][0] = (t_position){.x = 1, .y = 0};
	positions[6][1] = (t_position){.x = 2, .y = 0};
	positions[6][2] = (t_position){.x = 0, .y = 1};
	positions[6][3] = (t_position){.x = 1, .y = 1};
	positions[7][0] = (t_position){.x = 1, .y = 0};
	positions[7][1] = (t_position){.x = 2, .y = 0};
	positions[7][2] = (t_position){.x = 0, .y = 1};
	positions[7][3] = (t_position){.x = 1, .y = 1};
	positions[8][0] = (t_position){.x = 0, .y = 0};
	positions[8][1] = (t_position){.x = 1, .y = 0};
	positions[8][2] = (t_position){.x = 2, .y = 0};
	positions[8][3] = (t_position){.x = 1, .y = 1};
	positions[9][0] = (t_position){.x = 1, .y = 0};
	positions[9][1] = (t_position){.x = 2, .y = 0};
	positions[9][2] = (t_position){.x = 0, .y = 1};
	positions[9][3] = (t_position){.x = 1, .y = 1};
	positions[10][0] = (t_position){.x = 1, .y = 0};
	positions[10][1] = (t_position){.x = 2, .y = 0};
	positions[10][2] = (t_position){.x = 0, .y = 1};
	positions[10][3] = (t_position){.x = 1, .y = 1};
	positions[11][0] = (t_position){.x = 1, .y = 0};
	positions[11][1] = (t_position){.x = 2, .y = 0};
	positions[11][2] = (t_position){.x = 0, .y = 1};
	positions[11][3] = (t_position){.x = 1, .y = 1};
	positions[12][0] = (t_position){.x = 1, .y = 0};
	positions[12][1] = (t_position){.x = 2, .y = 0};
	positions[12][2] = (t_position){.x = 0, .y = 1};
	positions[12][3] = (t_position){.x = 1, .y = 1};
	positions[13][0] = (t_position){.x = 0, .y = 0};
	positions[13][1] = (t_position){.x = 1, .y = 0};
	positions[13][2] = (t_position){.x = 2, .y = 0};
	positions[13][3] = (t_position){.x = 1, .y = 1};
	positions[14][0] = (t_position){.x = 1, .y = 0};
	positions[14][1] = (t_position){.x = 2, .y = 0};
	positions[14][2] = (t_position){.x = 0, .y = 1};
	positions[14][3] = (t_position){.x = 1, .y = 1};
	positions[15][0] = (t_position){.x = 1, .y = 0};
	positions[15][1] = (t_position){.x = 2, .y = 0};
	positions[15][2] = (t_position){.x = 0, .y = 1};
	positions[15][3] = (t_position){.x = 1, .y = 1};
	positions[16][0] = (t_position){.x = 0, .y = 0};
	positions[16][1] = (t_position){.x = 0, .y = 1};
	positions[16][2] = (t_position){.x = 0, .y = 2};
	positions[16][3] = (t_position){.x = 0, .y = 3};
	positions[17][0] = (t_position){.x = 1, .y = 0};
	positions[17][1] = (t_position){.x = 2, .y = 0};
	positions[17][2] = (t_position){.x = 0, .y = 1};
	positions[17][3] = (t_position){.x = 1, .y = 1};
	positions[18][0] = (t_position){.x = 1, .y = 0};
	positions[18][1] = (t_position){.x = 2, .y = 0};
	positions[18][2] = (t_position){.x = 0, .y = 1};
	positions[18][3] = (t_position){.x = 1, .y = 1};
	positions[19][0] = (t_position){.x = 0, .y = 0};
	positions[19][1] = (t_position){.x = 0, .y = 1};
	positions[19][2] = (t_position){.x = 0, .y = 2};
	positions[19][3] = (t_position){.x = 1, .y = 2};
	positions[20][0] = (t_position){.x = 1, .y = 0};
	positions[20][1] = (t_position){.x = 2, .y = 0};
	positions[20][2] = (t_position){.x = 0, .y = 1};
	positions[20][3] = (t_position){.x = 1, .y = 1};
	positions[21][0] = (t_position){.x = 1, .y = 0};
	positions[21][1] = (t_position){.x = 2, .y = 0};
	positions[21][2] = (t_position){.x = 0, .y = 1};
	positions[21][3] = (t_position){.x = 1, .y = 1};
	positions[22][0] = (t_position){.x = 0, .y = 0};
	positions[22][1] = (t_position){.x = 1, .y = 0};
	positions[22][2] = (t_position){.x = 2, .y = 0};
	positions[22][3] = (t_position){.x = 3, .y = 0};
	/* ft_memcpy(positions[0], positions[*nb_tetri], 4 * sizeof(t_position)); */
	/* *nb_tetri = 1; */
}

int		is_type_already_created(t_type *types, t_position **positions,
								int nb_types)
{
	int index;

	index = 0;
	while (index < nb_types)
	{
		if (ft_memcmp(positions, &types[index].points, 4 * sizeof(t_position)) == 0)
			return (index);
		index++;
	}
	return (-1);
}

void	generate_types(t_type *types, t_position **positions,
						t_tetri *tetriminos, int nb_tetri)
{
	int index;
	int type_index;

	index = 0;
	while (index < nb_tetri)
	{
		type_index = is_type_already_created(types, &positions[index], index);
		if (type_index == -1)
		{
			ft_memcpy(types[index].points, positions[index],
				4 * sizeof(t_position));
			generate_type_values(&types[index]);
			tetriminos[index].type = &types[index];
		}
		else
			tetriminos[index].type = &types[type_index];
		index++;
	}
}

void	print_usage(char *prog_name)
{
	ft_putstr("usage: ");
	ft_putstr(prog_name);
	ft_putstr(" <fillit_file>\n");
}

int		main(int argc, char *argv[])
{
	t_tetri		tetriminos[MAX_TETRI];
	int			nb_tetri;
	t_type		types[MAX_TETRI];
	t_position	*positions[26];

	if (argc != 2)
		print_usage(argv[0]);
	else
	{
		parse_file(argv[1], &nb_tetri, positions);
		generate_types(types, positions, tetriminos, nb_tetri);
		solve_and_print(tetriminos, nb_tetri);
	}
	return (0);
}
