/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:57:31 by hthiessa          #+#    #+#             */
/*   Updated: 2019/01/14 18:11:41 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef char **t_tetri;

typedef char **t_grid;

t_tetri	*parse_file(char *filename)
{
	(void)filename;
	return (NULL);
}

void	print_usage(char *prog_name)
{
	ft_putstr("usage: ");
	ft_putstr(prog_name);
	ft_putstr(" <fillit_file>\n");
}

void	*ft_calloc(size_t size, int c)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	return (ft_memset(mem, c, size));
}

t_grid	*create_grid(size_t max_tetri)
{
	size_t	i;
	t_grid	*grid;

	if (!(grid = malloc(max_tetri * 4 * sizeof(**grid))))
		return (NULL);
	i = 0;
	while (i < max_tetri)
	{
		if (!(grid[i] = ft_calloc(max_tetri * 4 * sizeof(***grid), '.')))
			return (NULL); //TODO free everything
		i++;
	}
	return (grid);
}

void	copy_grid(size_t max_tetri, t_grid dst, t_grid src)
{
	size_t i;

	i = 0;
	while (i < max_tetri)
	{
		ft_memcpy(dst[i], src[i], max_tetri * 4);
		i++;
	}
}

t_grid	*resolve(t_tetri tetriminos[])
{
	size_t	nb_tetri;
	t_grid	*grid;
	t_grid	*best_grid;

	nb_tetri = 0;
	while (tetriminos[nb_tetri])
		nb_tetri++;
	grid = create_grid(nb_tetri);
	best_grid = create_grid(nb_tetri);
	return (best_grid);
}

t_grid	resolve_rec(t_tetri tetriminos[], t_grid *grid, size_t n,
					size_t max_tetri)
{
	(void)tetriminos;
	(void)grid;
	(void)n;
	(void)max_tetri;
	/*
	if (n == max_tetri)
	{
		//check si c'est plus petit
	}
	else
	{
		//TODO
	}
	*/
	return (NULL);
}

void	print_grid(t_grid *grid)
{
	(void)grid;
	ft_putstr("Trololol\n");
}

int		main(int argc, char *argv[])
{
	t_tetri	*tetriminos;
	t_grid	*grid;

	if (argc != 2)
		print_usage(argv[0]);
	else
	{
		tetriminos = parse_file(argv[1]);
		if (!(grid = resolve(tetriminos)))
			return (1); //TODO
		print_grid(grid);
	}
	return (0);
}
