/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:43:12 by hbode             #+#    #+#             */
/*   Updated: 2018/11/30 17:18:58 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		intlen(long n)
{
	int		len;

	len = 0;
	if (n <= 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*fillstr(char *s, long nb, int i)
{
	s[i--] = 0;
	if (nb == 0)
	{
		s[0] = '0';
		return (s);
	}
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		s[i] = '0' + nb % 10;
		nb /= 10;
		i--;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;
	long	nb;

	nb = (long)n;
	i = intlen(nb);
	if (!(s = (char*)malloc((i + 1) * sizeof(char))))
		return (NULL);
	s = fillstr(s, nb, i);
	return (s);
}
