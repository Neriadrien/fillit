/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:07:25 by hbode             #+#    #+#             */
/*   Updated: 2018/11/30 17:53:53 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_first_index(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			return (i);
		i++;
	}
	return (0);
}

static int		get_last_index(char const *s)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (s[i])
	{
		if (!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			return (i);
		i--;
	}
	return (ft_strlen(s) - 1);
}

static int		check_valid_str(char const *s, int start, int end)
{
	int		i;

	i = start;
	while (i < (end + 1))
	{
		if (!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		start;
	int		end;

	i = -1;
	if (!s)
		return (NULL);
	start = get_first_index(s);
	end = get_last_index(s);
	if (check_valid_str(s, start, end) == 0)
	{
		if (!(str = (char*)malloc(sizeof(char))))
			return (NULL);
		str[0] = 0;
		return (str);
	}
	if (!(str = (char*)malloc((((end + 1) - start) + 1) * sizeof(char))))
		return (NULL);
	while (++i < ((end + 1) - start))
		str[i] = s[i + start];
	str[i] = 0;
	return (str);
}
