/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:33:17 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/16 16:33:18 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*pdest;
	char	*psrc;

	pdest = (char *)dest;
	psrc = (char *)src;
	while (i < n)
		pdest[i] = psrc[i];
}
