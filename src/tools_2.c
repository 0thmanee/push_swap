/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:24:58 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/25 19:48:34 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			if (i == 0 || s[i - 1] == c)
				count++;
			i++;
		}
	}
	return (count);
}

static size_t	calc_len(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	return (count);
}

static char	*fill_subs(char const **s, char c)
{
	size_t	i;
	char	*subs;
	size_t	len;

	while (**s == c && **s)
		(*s)++;
	len = calc_len(*s, c);
	subs = (char *) malloc (sizeof (char) * (len + 1));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = **s;
		i++;
		(*s)++;
	}
	subs[i] = '\0';
	return (subs);
}

char	**ft_split(char const *s, char c)
{
	size_t	nbr_words;
	char	**strings;
	size_t	i;

	i = 0;
	if (!s || !s[0] || count_words(s, c) == 0)
		return (NULL);
	nbr_words = count_words(s, c);
	strings = (char **) malloc (sizeof(char *) * (nbr_words + 1));
	if (!strings)
		return (NULL);
	while (i < nbr_words)
	{
		strings[i] = fill_subs(&s, c);
		if (!strings[i])
		{
			while (i > 0)
				free(strings[--i]);
			free (strings);
			return (NULL);
		}
		i++;
	}
	strings[i] = NULL;
	return (strings);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
