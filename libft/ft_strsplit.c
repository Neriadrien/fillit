/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:12:27 by hbode             #+#    #+#             */
/*   Updated: 2018/11/29 20:39:49 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_word_len(char const *s, int i, char c)
{
	int		len;

	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (len);
		i++;
		len++;
	}
	return (len);
}

static int		count_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			i += get_word_len(s, i, c);
		}
		else
			i++;
	}
	return (words);
}

static char		*extract_characters(char const *s, int i, int word_len, char c)
{
	char	*word;
	int		j;

	j = 0;
	if (!(word = (char*)malloc((word_len + 1) * sizeof(char))))
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			break ;
		word[j] = s[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char		*extract_word(char const *s, int word_index, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			if (words == word_index)
				break ;
			else
				i += get_word_len(s, i, c);
		}
		i++;
	}
	return (extract_characters(s, i, get_word_len(s, i, c), c));
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	if (!(tab = (char**)malloc((words + 1) * sizeof(char*))))
		return (NULL);
	tab[words] = 0;
	while (i < words)
	{
		tab[i] = extract_word(s, i + 1, c);
		i++;
	}
	return (tab);
}
