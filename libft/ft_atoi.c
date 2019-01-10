/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:42:12 by hbode             #+#    #+#             */
/*   Updated: 2018/11/30 17:30:06 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		char_is_number(const char *str, int index)
{
	if (str[index] >= '0' && str[index] <= '9')
		return (1);
	else
		return (0);
}

static int		char_to_int(const char *str, int index)
{
	int		result;

	result = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + str[index] - '0';
		index++;
	}
	return (result);
}

int				ft_atoi(const char *str)
{
	int		i;

	i = 0;
	while (i >= 0)
	{
		if ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
			i++;
		else if (str[i] == '+' && char_is_number(str, i + 1) == 1)
			return (char_to_int(str, i + 1));
		else if (str[i] == '-' && char_is_number(str, i + 1) == 1)
			return (-1 * char_to_int(str, i + 1));
		else if (str[i] >= '0' && str[i] <= '9')
			return (char_to_int(str, i));
		else
			return (0);
	}
	return (0);
}
