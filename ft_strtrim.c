/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:58:52 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/22 11:57:57 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inset(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	first;
	size_t	last;
	
	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1);
	while (inset(s1[first], set))
		first++;
	while (inset(s1[last - 1], set))
		last--;
	return (ft_substr(s1, first, last - first));
}
