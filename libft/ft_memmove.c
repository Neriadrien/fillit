/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 06:56:33 by hbode             #+#    #+#             */
/*   Updated: 2018/11/30 16:47:33 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*movebackward(void *dst, const void *src, size_t len)
{
	while (len-- > 0)
		((char*)dst)[len] = ((char*)src)[len];
	return (dst);
}

static void		*moveforward(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (dst);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src)
		return (dst);
	if (dst < src)
		dst = moveforward(dst, src, len);
	else
		dst = movebackward(dst, src, len);
	return (dst);
}
