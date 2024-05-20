/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:08:15 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/20 09:08:16 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizecalc(long nb, int neg)
{
	int	size;

	size = 0;
	if (neg)
		size++;
	while (nb)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static void	ft_convert(char *str, long nb, int size, int neg)
{
	str[size] = '\0';
	while (size > 0)
	{
		str[--size] = (nb % 10) + '0';
		nb /= 10;
	}
	if (neg)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		neg;
	long	nb;

	nb = n;
	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
	}
	size = ft_sizecalc(nb, neg);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_convert(str, nb, size, neg);
	return (str);
}
