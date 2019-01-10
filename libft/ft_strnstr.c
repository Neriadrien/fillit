/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:31:55 by hbode             #+#    #+#             */
/*   Updated: 2018/11/30 14:25:25 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;

	i = 0;
	while (haystack[i] && len-- >= ft_strlen(needle))
	{
		if (ft_memcmp(haystack + i, needle, ft_strlen(needle)) == 0)
			return ((char*)haystack + i);
		i++;
	}
	return (0);
}
