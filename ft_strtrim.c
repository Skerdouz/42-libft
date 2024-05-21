/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:58:52 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/21 09:05:00 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

static char	*ft_strinit(const char *src, int start, int end)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = malloc ((end - start) * sizeof(char));
	if (!dest)
		return (NULL);
	while (start <= end)
		dest[i++] = src[start++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (ft_inset(s1[i], set))
			i++;
		else
			break ;
	}
	j = ft_strlen(s1) - 1;
	while (j)
	{
		if (ft_inset(s1[j], set))
			j--;
		else
			break ;
	}
	str = ft_strinit(s1, i, j);
	return (str);
}
