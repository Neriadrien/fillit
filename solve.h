#ifndef SOLVE_H_
# define SOLVE_H_

# include "utils.h"

typedef struct	s_tetri
{
	t_tetritype	*type;
	t_position	position;
}				t_tetri;
typedef short int t_grid[16];

void	print_and_exit(t_tetri *tetriminos_to_free);
void	solve_and_print(t_tetri *tetriminos, int nb_tetri);
void	solve_and_print_rec(int index, t_tetri *tetriminos, t_grid grid,
							int nb_tetri, int actual_width);


#endif
