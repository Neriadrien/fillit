/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:38:07 by hbode             #+#    #+#             */
/*   Updated: 2018/11/29 13:42:20 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_word_len(char *str, int i)
{
	int		len;

	len = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			return (len);
		i++;
		len++;
	}
	return (len);
}

static int		count_words(char *str)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			words++;
			i += get_word_len(str, i);
		}
		else
			i++;
	}
	return (words);
}

static char		*extract_characters(char *str, int i, int word_len)
{
	char	*word;
	int		j;

	j = 0;
	if (!(word = malloc((word_len + 1) * sizeof(char))))
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			break ;
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char		*extract_word(char *str, int word_index)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			words++;
			if (words == word_index)
				break ;
			else
				i += get_word_len(str, i);
		}
		i++;
	}
	return (extract_characters(str, i, get_word_len(str, i)));
}

char			**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	words = count_words(str);
	if (!(tab = malloc((words + 1) * sizeof(char*))))
		return (0);
	tab[words] = 0;
	while (i < words)
	{
		tab[i] = extract_word(str, i + 1);
		i++;
	}
	return (tab);
}
