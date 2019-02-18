/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:58:23 by hbode             #+#    #+#             */
/*   Updated: 2019/02/04 19:44:16 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "utils.h"

# define BUF_SIZE 21

typedef char t_tetris[4][4];

int		check_argc(int argc);
int		check_left(char *tetri, int i);
int		check_right(char *tetri, int i);
int		check_top(char *tetri, int i);
int		check_bot(char *tetri, int i);
void	set_all_left(t_points *grid, int count);
int		parse(char *file, t_points *grid);

#endif
