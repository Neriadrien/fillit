/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:39:47 by hbode             #+#    #+#             */
/*   Updated: 2018/11/29 13:40:10 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	temp;

	i = 0;
	length = ft_strlen(str) - 1;
	while (i < length)
	{
		temp = *(str + i);
		*(str + i) = *(str + length);
		*(str + length) = temp;
		i++;
		length--;
	}
	return (str);
}
