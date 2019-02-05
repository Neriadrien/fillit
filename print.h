/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:06:32 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/04 16:02:16 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "utils.h"
# include "solve.h"

void	print_grid(char *grid[], int width);
void	print_and_exit(t_solve_data *data);
void	print_tab_short_int(int id, short int *tab);

#endif
