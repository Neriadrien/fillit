/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_adjacent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:35:09 by hbode             #+#    #+#             */
/*   Updated: 2019/02/04 19:35:23 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_left(char *tetri, int i)
{
	if (i % 5 == 0)
		return (0);
	return (tetri[i - 1] == '#');
}

int		check_right(char *tetri, int i)
{
	if ((i % 5) - 3 == 0)
		return (0);
	return (tetri[i + 1] == '#');
}

int		check_top(char *tetri, int i)
{
	if (i / 5 == 0)
		return (0);
	return (tetri[i - 5] == '#');
}

int		check_bot(char *tetri, int i)
{
	if (i / 5 == 3)
		return (0);
	return (tetri[i + 5] == '#');
}
