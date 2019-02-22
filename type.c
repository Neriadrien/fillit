#include "libft/libft.h"
#include "utils.h"

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
	type->last_position = (t_position){.x = 0, .y = 0};
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