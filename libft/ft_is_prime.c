/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:17:59 by hbode             #+#    #+#             */
/*   Updated: 2018/11/29 13:18:14 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_prime(int nb)
{
	int	i;
	int	max;

	i = 2;
	max = (nb < 46341) ? nb : 46341;
	if (nb <= 1)
		return (0);
	while (i < max)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}