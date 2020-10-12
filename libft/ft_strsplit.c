/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:54:21 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/11 05:55:23 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char static	*slovo(int start, char const *s, char c)
{
	int		x;
	int		super_start;
	char	*str;

	x = 0;
	super_start = start;
	while (s[start] != c && s[start] != 0)
	{
		start++;
		x++;
	}
	str = (char*)malloc(sizeof(char) * (x + 1));
	x = 0;
	while (s[super_start] != c && s[super_start] != 0)
		str[x++] = s[super_start++];
	str[x] = 0;
	return (str);
}

char static	*count_words(char const *s, char c, int word_code)
{
	int		x;
	int		word;
	int		start;

	start = 0;
	x = 0;
	word = 0;
	if (s[x] != c && s[x] != 0 && word_code != word++)
	{
		if (word_code == 1)
			return (slovo(start, s, c));
		else
			x++;
	}
	while (s[x] != 0 && word_code != word)
	{
		if (s[x] == c)
			if (s[x + 1] != c && s[x + 1] != 0 && word_code != word++)
				start = x + 1;
		x++;
	}
	return (slovo(start, s, c));
}

static int	count_word(char const *s, char c)
{
	int		word;
	int		x;

	word = 0;
	x = 0;
	if (s[x] != c && s[x] != 0)
	{
		word++;
		x++;
	}
	while (s[x] != 0)
	{
		if (s[x] == c)
			if (s[x + 1] != c && s[x + 1] != 0)
				word++;
		x++;
	}
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	int		word;
	int		word_code;
	char	**massive;
	int		xmas;

	if (!s)
		return (NULL);
	xmas = 0;
	word = count_word(s, c);
	word_code = 1;
	massive = (char**)malloc(sizeof(char*) * (word + 1));
	if (!massive)
		return (NULL);
	while (word_code <= word)
	{
		massive[word_code - 1] = count_words(s, c, word_code);
		word_code++;
	}
	massive[word_code - 1] = (char*)malloc(sizeof(char));
	massive[word_code - 1] = NULL;
	return (massive);
}
