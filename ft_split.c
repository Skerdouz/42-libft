#include "libft.h"

static	size_t	ft_wordcount(char const *s, char c)
{
	size_t	counter;
	size_t	in_word;
	size_t	i;

	in_word = 0;
	counter = 0;
	i = 0;
	while (s[i])
	{
		if (!in_word && s[i] != c)
		{
			counter++;
			in_word = 1;
		}
		if (in_word && (s[i] == c || s[i] == '\0'))
		{
			counter++;
			in_word = 0;
		}
		i++;
	}
	return (counter);
}

static void	ft_wordcpy(char const *s, char *subarray, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start <= end)
		subarray[i++] = s[start++];
	subarray[i] = '\0';
}

static void	ft_wordalloc(char const *s, char **array, char c)
{
	size_t	i;
	size_t	j;
	size_t	in_word;
	size_t	start;

	i = 0;
	j = 0;
	in_word = 0;
	while (s[i])
	{
		if (!in_word && s[i] != c)
		{
			start = i;
			in_word = 1;
		}
		if (in_word && (s[i] == c || s[i] == '\0'))
		{
			array[j] = malloc(((i - start) + 1) * sizeof(char));
			ft_wordcpy(s, array[j], start, (i - 1));
			in_word = 0;
			j++;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	word_count;

	word_count = ft_wordcount(s, c);
	array = malloc(word_count * sizeof(char *));
	ft_wordalloc(s, array, c);
	return (array);
}
