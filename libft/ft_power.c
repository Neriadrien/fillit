/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:26:47 by hbode             #+#    #+#             */
/*   Updated: 2018/11/29 13:28:35 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	int		result;

	result = 1;
	if (power < 0)
		return (0);
	else if (power > 0)
		result = nb * ft_power(nb, power - 1);
	return (result);
}
