/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:19:03 by gabsanch          #+#    #+#             */
/*   Updated: 2023/05/27 21:37:28 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char limit)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != limit)
		{
			word++;
			while (s[i] != limit && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;
	int		size;
	int		j;

	i = 0;
	j = -1;
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (++j < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		split[j] = ft_substr(s, i, size);
		if (split[j] == NULL)
		{
			ft_free(split, j);
			return (NULL);
		}
		i += size;
	}
	split[j] = 0;
	return (split);
}
