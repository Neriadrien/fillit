/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:21:27 by hbode             #+#    #+#             */
/*   Updated: 2018/11/29 13:22:49 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		*tab;
	int		len;
	int		i;

	i = 0;
	if (min >= max)
		return (0);
	len = max - min;
	if (!(tab = malloc(len * sizeof(int))))
		return (0);
	while (i < len)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
