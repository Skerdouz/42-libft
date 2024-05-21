/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:49:39 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/21 16:49:40 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//TODO: Fix this function

static int malloc_init(char **array, int pos, int size)
{
	int	i;

	i = 0;
	array[pos] = malloc(size * sizeof(char));
	if (!array[pos])
	{
		while (i < pos)
			free(array[i++]);
		free(array);
		return (1);
	}
	return (0);
}

static int array_init(char **array, const char *s, char delimiter)
{
	int	i;
	int	size;

	i = 0;
	while (*s)
	{
		size = 0;
		while (*s == delimiter && *s)
			s++;
		while (*s != delimiter && *s)
		{
			s++;
			size++;
		}
		if (size)
		{
			if (malloc_init(array, i, size + 1))
				return (1);
			ft_strlcpy(array[i], s - size, size + 1);
			i++;
		}
	}
	return (0);
}

static int count_words(const char *str, char delimiter)
{
	int	in_word;
	int	counter;

	in_word = 0;
	counter = 0;
	while (*str)
	{
		if (*str != delimiter && !in_word)
		{
			in_word = 1;
			counter++;
		}
		if (*str == delimiter && in_word)
			in_word = 0;
		str++;		
	}
	return (counter);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	array = malloc((word_count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array[word_count] = NULL;
	if (array_init(array, s, c))
		return (NULL);
	return (array);
}