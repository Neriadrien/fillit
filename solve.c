#include <stdlib.h>

#include "solve.h"
#include "utils.h"

typedef short int t_grid[16];

void	print_and_exit(t_tetri *tetriminos_to_free)
{
	(void)tetriminos_to_free;
	//print
	//free
	exit(0);
}

void	solve_and_print_rec(int index, t_tetri *tetriminos, t_grid grid,
							int nb_tetri)
{
	t_tetri		tetri;
	long int	*grid_for_cmp;

	if (index == nb_tetri)
		print_and_exit(tetriminos);
	tetri = tetriminos[index];
	tetri.position = (t_position) {0, 0};
	while (tetri.position.y < MAX_WIDTH - tetri.type->height)
	{
		grid_for_cmp = (long*)(grid + tetri.position.y);
		while (tetri.position.x < MAX_WIDTH - tetri.type->width)
		{
			if (tetri.type->cache[tetri.position.x] == 0)
				tetri.type->cache[tetri.position.x] =
					tetri.type->cache[tetri.position.x] >> tetri.position.x;
			if ((*grid_for_cmp & tetri.type->cache[tetri.position.x]) == 0)
			{
				*grid_for_cmp ^= tetri.type->cache[tetri.position.x];
				solve_and_print_rec(index + 1, tetriminos, grid, nb_tetri);
				*grid_for_cmp ^= tetri.type->cache[tetri.position.x];
			}
			tetri.position.x++;
		}
		tetri.position.y++;
	}
}
