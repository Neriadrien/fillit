#ifndef UTILS_H_
# define UTILS_H_

# define MAX_WIDTH

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

#endif
