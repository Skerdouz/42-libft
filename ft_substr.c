/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:15:16 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/22 17:07:23 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	result = malloc (len + 1 * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len && start < ft_strlen(s))
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
