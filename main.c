/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:57:31 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/20 19:13:00 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "solve.h"
#include "fillit.h"
#include "type.h"

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
	t_points	positions[MAX_TETRI];

	if (argc != 2)
		print_usage(argv[0]);
	else
	{
		ft_bzero(types, MAX_TETRI * sizeof(t_type));
		nb_tetri = parse(argv[1], positions);
		generate_types(types, positions, tetriminos, nb_tetri);
		solve_and_print(tetriminos, nb_tetri);
	}
	return (0);
}
