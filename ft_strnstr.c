/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:08:18 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/16 11:08:18 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return (s1[i] - s2[i]);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	const char *ptr;

	if (!big && !len)
		return (0);
	if (!little[0] || little == big)
		return ((char *)big);
	little_len = ft_strlen(little);
	while (len >= little_len && (ptr = ft_memchr(big, little[0], len)))
	{
		if (!ft_strncmp(ptr, little, little_len))
			return ((char *)ptr);
		len -= (ptr - big) + 1;
		big = ptr + 1;
	}
	return (0);
}
