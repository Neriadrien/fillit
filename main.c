/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:57:31 by hthiessa          #+#    #+#             */
/*   Updated: 2019/01/21 17:19:07 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "solve.h"

int		max(int first, int second)
{
	return (first > second ? first : second);
}

void generate_type_values(t_tetritype* type)
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
		((short int*)&type->mask)[type->points[point].y]
			^= 1 << (sizeof(short int) * 8 - 1 - type->points[point].x);
		point++;
	}
}

t_tetri	*parse_file(char *filename, int *nb_tetri)
{
	t_tetri		*tetriminos;
	t_tetritype	*types;

	(void)filename;
	*nb_tetri = 23;
	if (!(tetriminos = malloc(*nb_tetri * sizeof(*tetriminos))))
		return (NULL);
	if (!(types = malloc(*nb_tetri * sizeof(*types))))
		return (NULL);
	ft_memset(tetriminos, 0, *nb_tetri * sizeof(*tetriminos));
	ft_memset(types, 0, *nb_tetri * sizeof(*types));

	types[0].points[0] = (t_position){.x = 1, .y = 0};
	types[0].points[1] = (t_position){.x = 2, .y = 0};
	types[0].points[2] = (t_position){.x = 0, .y = 1};
 	types[0].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[0] = (t_tetri){.type = &types[0]};
	types[1].points[0] = (t_position){.x = 0, .y = 0};
	types[1].points[1] = (t_position){.x = 1, .y = 0};
	types[1].points[2] = (t_position){.x = 1, .y = 1};
	types[1].points[3] = (t_position){.x = 1, .y = 2};
	tetriminos[1] = (t_tetri){.type = &types[1]};
	tetriminos[2] = (t_tetri){.type = &types[0]};
	tetriminos[3] = (t_tetri){.type = &types[0]};
	tetriminos[4] = (t_tetri){.type = &types[0]};
	tetriminos[5] = (t_tetri){.type = &types[0]};
	tetriminos[6] = (t_tetri){.type = &types[0]};
	tetriminos[7] = (t_tetri){.type = &types[0]};
	types[8].points[0] = (t_position){.x = 0, .y = 0};
	types[8].points[1] = (t_position){.x = 1, .y = 0};
	types[8].points[2] = (t_position){.x = 2, .y = 0};
	types[8].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[8] = (t_tetri){.type = &types[8]};
	tetriminos[9] = (t_tetri){.type = &types[0]};
	tetriminos[10] = (t_tetri){.type = &types[0]};
	tetriminos[11] = (t_tetri){.type = &types[0]};
	tetriminos[12] = (t_tetri){.type = &types[0]};
	tetriminos[13] = (t_tetri){.type = &types[8]};
	tetriminos[14] = (t_tetri){.type = &types[0]};
	tetriminos[15] = (t_tetri){.type = &types[0]};
	types[16].points[0] = (t_position){.x = 0, .y = 0};
	types[16].points[1] = (t_position){.x = 0, .y = 1};
	types[16].points[2] = (t_position){.x = 0, .y = 2};
	types[16].points[3] = (t_position){.x = 0, .y = 3};
	tetriminos[16] = (t_tetri){.type = &types[16]};
	tetriminos[17] = (t_tetri){.type = &types[0]};
	tetriminos[18] = (t_tetri){.type = &types[0]};
	types[19].points[0] = (t_position){.x = 0, .y = 0};
	types[19].points[1] = (t_position){.x = 0, .y = 1};
	types[19].points[2] = (t_position){.x = 0, .y = 2};
	types[19].points[3] = (t_position){.x = 1, .y = 2};
	tetriminos[19] = (t_tetri){.type = &types[19]};
	tetriminos[20] = (t_tetri){.type = &types[0]};
	tetriminos[21] = (t_tetri){.type = &types[0]};
	types[22].points[0] = (t_position){.x = 0, .y = 0};
	types[22].points[1] = (t_position){.x = 1, .y = 0};
	types[22].points[2] = (t_position){.x = 2, .y = 0};
	types[22].points[3] = (t_position){.x = 3, .y = 0};
	tetriminos[22] = (t_tetri){.type = &types[22]};


	*nb_tetri = ft_atoi(filename);

	int tetri = 0;

	while (tetri < *nb_tetri)
	{
		generate_type_values(&types[tetri]);
		tetri++;
	}

	return (tetriminos);
}

int		is_type_already_created(t_tetritype *types, t_position *(positions[4]),
								int nb_types)
{
	int index;

	index = 0;
	while (index < nb_types)
	{
		if (ft_memcmp(positions, &types[index].points, 4 * sizeof(t_position)))
			return (1);
		index++;
	}
	return (0);
}

void	generate_types(t_tetritype *types, t_position *(positions[4]),
					   t_tetri *tetriminos, int nb_tetri)
{
	int index;

	ft_memcpy(types[0].points, &positions[0], 4 * sizeof(t_position));
	generate_type_values(&types[0]);
	index = 1;
	while (index < nb_tetri)
	{
		if (!is_type_already_created(types, &positions[index], index))
		{
			ft_memcpy(types[index].points, &positions[index],
					  4 * sizeof(t_position));
			generate_type_values(&types[index]);
		}
		tetriminos[index].type = &types[index];
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
	t_tetri		*tetriminos;	//TODO [26]
	int			nb_tetri;
	t_tetritype types[26];
	t_position	positions[26][4];

	(void)types;
	(void)positions;
	if (argc != 2)
		print_usage(argv[0]);
	else
	{
		if (!(tetriminos = parse_file(argv[1], &nb_tetri)))
			return (1);
		solve_and_print(tetriminos, nb_tetri);
	}
	return (0);
}
