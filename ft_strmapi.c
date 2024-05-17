/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:48:23 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/17 16:48:24 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	i = 0;
	while (s[i])
		i++;
	result = malloc(i * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
		result[i] = (*f)(i, s[i]);
	return (result);
}
