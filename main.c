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

#include <stdio.h>

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
	/* types[0] = (t_tetritype){.height = 2, .width = 2}; */
	/* types[0].points[0] = (t_position){.x = 0, .y = 0}; */
	/* types[0].points[1] = (t_position){.x = 0, .y = 1}; */
	/* types[0].points[2] = (t_position){.x = 1, .y = 0}; */
	/* types[0].points[3] = (t_position){.x = 1, .y = 1}; */
	/* types[0].cache[0] = 0b1100000000000000110000000000000000000000000000000000000000000000; */
	/* tetriminos[0] = (t_tetri){.type = &types[0]}; */
	/* types[1] = (t_tetritype){.height = 3, .width = 2}; */
	/* types[1].points[0] = (t_position){.x = 1, .y = 0}; */
	/* types[1].points[1] = (t_position){.x = 1, .y = 1}; */
	/* types[1].points[2] = (t_position){.x = 1, .y = 2}; */
	/* types[1].points[3] = (t_position){.x = 0, .y = 2}; */
	/* types[1].cache[0] = 0b0100000000000000010000000000000011000000000000000000000000000000; */
	/* tetriminos[1] = (t_tetri){.type = &types[1]}; */
	/* types[2] = (t_tetritype){.height = 2, .width = 3}; */
	/* types[2].points[0] = (t_position){.x = 0, .y = 0}; */
	/* types[2].points[1] = (t_position){.x = 0, .y = 1}; */
	/* types[2].points[2] = (t_position){.x = 1, .y = 1}; */
	/* types[2].points[3] = (t_position){.x = 2, .y = 1}; */
	/* types[2].cache[0] = 0b1000000000000000111000000000000000000000000000000000000000000000; */
	/* tetriminos[2] = (t_tetri){.type = &types[2]}; */



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
	types[2].points[0] = (t_position){.x = 1, .y = 0};
	types[2].points[1] = (t_position){.x = 2, .y = 0};
	types[2].points[2] = (t_position){.x = 0, .y = 1};
	types[2].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[2] = (t_tetri){.type = &types[2]};
	types[3].points[0] = (t_position){.x = 1, .y = 0};
	types[3].points[1] = (t_position){.x = 2, .y = 0};
	types[3].points[2] = (t_position){.x = 0, .y = 1};
	types[3].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[3] = (t_tetri){.type = &types[3]};
	types[4].points[0] = (t_position){.x = 1, .y = 0};
	types[4].points[1] = (t_position){.x = 2, .y = 0};
	types[4].points[2] = (t_position){.x = 0, .y = 1};
	types[4].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[4] = (t_tetri){.type = &types[4]};
	types[5].points[0] = (t_position){.x = 1, .y = 0};
	types[5].points[1] = (t_position){.x = 2, .y = 0};
	types[5].points[2] = (t_position){.x = 0, .y = 1};
	types[5].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[5] = (t_tetri){.type = &types[5]};
	types[6].points[0] = (t_position){.x = 1, .y = 0};
	types[6].points[1] = (t_position){.x = 2, .y = 0};
	types[6].points[2] = (t_position){.x = 0, .y = 1};
	types[6].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[6] = (t_tetri){.type = &types[6]};
	types[7].points[0] = (t_position){.x = 1, .y = 0};
	types[7].points[1] = (t_position){.x = 2, .y = 0};
	types[7].points[2] = (t_position){.x = 0, .y = 1};
	types[7].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[7] = (t_tetri){.type = &types[7]};
	types[8].points[0] = (t_position){.x = 0, .y = 0};
	types[8].points[1] = (t_position){.x = 1, .y = 0};
	types[8].points[2] = (t_position){.x = 2, .y = 0};
	types[8].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[8] = (t_tetri){.type = &types[8]};
	types[9].points[0] = (t_position){.x = 1, .y = 0};
	types[9].points[1] = (t_position){.x = 2, .y = 0};
	types[9].points[2] = (t_position){.x = 0, .y = 1};
	types[9].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[9] = (t_tetri){.type = &types[9]};
	types[10].points[0] = (t_position){.x = 1, .y = 0};
	types[10].points[1] = (t_position){.x = 2, .y = 0};
	types[10].points[2] = (t_position){.x = 0, .y = 1};
	types[10].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[10] = (t_tetri){.type = &types[10]};
	types[11].points[0] = (t_position){.x = 1, .y = 0};
	types[11].points[1] = (t_position){.x = 2, .y = 0};
	types[11].points[2] = (t_position){.x = 0, .y = 1};
	types[11].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[11] = (t_tetri){.type = &types[11]};
	types[12].points[0] = (t_position){.x = 1, .y = 0};
	types[12].points[1] = (t_position){.x = 2, .y = 0};
	types[12].points[2] = (t_position){.x = 0, .y = 1};
	types[12].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[12] = (t_tetri){.type = &types[12]};
	types[13].points[0] = (t_position){.x = 0, .y = 0};
	types[13].points[1] = (t_position){.x = 1, .y = 0};
	types[13].points[2] = (t_position){.x = 2, .y = 0};
	types[13].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[13] = (t_tetri){.type = &types[13]};
	types[14].points[0] = (t_position){.x = 1, .y = 0};
	types[14].points[1] = (t_position){.x = 2, .y = 0};
	types[14].points[2] = (t_position){.x = 0, .y = 1};
	types[14].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[14] = (t_tetri){.type = &types[14]};
	types[15].points[0] = (t_position){.x = 1, .y = 0};
	types[15].points[1] = (t_position){.x = 2, .y = 0};
	types[15].points[2] = (t_position){.x = 0, .y = 1};
	types[15].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[15] = (t_tetri){.type = &types[15]};
	types[16].points[0] = (t_position){.x = 0, .y = 0};
	types[16].points[1] = (t_position){.x = 0, .y = 1};
	types[16].points[2] = (t_position){.x = 0, .y = 2};
	types[16].points[3] = (t_position){.x = 0, .y = 3};
	tetriminos[16] = (t_tetri){.type = &types[16]};
	types[17].points[0] = (t_position){.x = 1, .y = 0};
	types[17].points[1] = (t_position){.x = 2, .y = 0};
	types[17].points[2] = (t_position){.x = 0, .y = 1};
	types[17].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[17] = (t_tetri){.type = &types[17]};
	types[18].points[0] = (t_position){.x = 1, .y = 0};
	types[18].points[1] = (t_position){.x = 2, .y = 0};
	types[18].points[2] = (t_position){.x = 0, .y = 1};
	types[18].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[18] = (t_tetri){.type = &types[18]};
	types[19].points[0] = (t_position){.x = 0, .y = 0};
	types[19].points[1] = (t_position){.x = 0, .y = 1};
	types[19].points[2] = (t_position){.x = 0, .y = 2};
	types[19].points[3] = (t_position){.x = 1, .y = 2};
	tetriminos[19] = (t_tetri){.type = &types[19]};
	types[20].points[0] = (t_position){.x = 1, .y = 0};
	types[20].points[1] = (t_position){.x = 2, .y = 0};
	types[20].points[2] = (t_position){.x = 0, .y = 1};
	types[20].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[20] = (t_tetri){.type = &types[20]};
	types[21].points[0] = (t_position){.x = 1, .y = 0};
	types[21].points[1] = (t_position){.x = 2, .y = 0};
	types[21].points[2] = (t_position){.x = 0, .y = 1};
	types[21].points[3] = (t_position){.x = 1, .y = 1};
	tetriminos[21] = (t_tetri){.type = &types[21]};
	types[22].points[0] = (t_position){.x = 0, .y = 0};
	types[22].points[1] = (t_position){.x = 1, .y = 0};
	types[22].points[2] = (t_position){.x = 2, .y = 0};
	types[22].points[3] = (t_position){.x = 3, .y = 0};
	tetriminos[22] = (t_tetri){.type = &types[22]};
	

	*nb_tetri = 10;

	int tetri = 0;
	int point = 0;

	while (tetri < *nb_tetri)
	{
		point = 0;
		//ft_memset(tetriminos[tetri].type->points, 0, 4 * sizeof(t_position));
		while (point < 4)
		{
			tetriminos[tetri].type->height = max(tetriminos[tetri].type->height, tetriminos[tetri].type->points[point].y + 1);
			tetriminos[tetri].type->width = max(tetriminos[tetri].type->width, tetriminos[tetri].type->points[point].x + 1);
			((short int*)&tetriminos[tetri].type->cache[0])
				[3 - tetriminos[tetri].type->points[point].y] ^= 1 << (sizeof(short int) * 8 - 1 - tetriminos[tetri].type->points[point].x);
			point++;
		}
		//printf("tetri %d: "LONG_TO_BINARY_PATTERN"\n\n", tetri, LONG_TO_BINARY(tetriminos[tetri].type->cache[0]));
		tetri++;
	}

	return (tetriminos);
}

void	print_usage(char *prog_name)
{
	ft_putstr("usage: ");
	ft_putstr(prog_name);
	ft_putstr(" <fillit_file>\n");
}

int		main(int argc, char *argv[])
{
	t_tetri	*tetriminos;
	int		nb_tetri;

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
