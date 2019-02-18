/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:57:31 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/18 17:34:53 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "solve.h"
#include "fillit.h"

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

int		is_type_already_created(t_type *types, t_points *positions,
								int nb_types)
{
	int index;

	index = 0;
	while (index < nb_types)
	{
		if (ft_memcmp(positions, &types[index].points, sizeof(t_points)) == 0)
			return (index);
		index++;
	}
	return (-1);
}

void	generate_types(t_type *types, t_points *positions,
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
			ft_memcpy(types[index].points, positions[index], sizeof(t_points));
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
	t_points	positions[26];

	if (argc != 2)
		print_usage(argv[0]);
	else
	{
		/* int index; */

		/* index = 0; */
		/* while (index < MAX_TETRI) */
		/* { */
		/* 	if (!(positions[index] = ft_memalloc(4 * sizeof(t_position)))) */
		/* 		exit(1); */
		/* 	index++; */
		/* } */
		nb_tetri = parse(argv[1], positions);
		generate_types(types, positions, tetriminos, nb_tetri);
		solve_and_print(tetriminos, nb_tetri);
	}
	return (0);
}
