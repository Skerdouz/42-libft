#include "libft.h"

static void	ft_convert(char *str, long nb, int size)
{
	while (size >= 0)
	{
		str[size--] = (nb % 10) + '0';
		nb /= 10;
	}
}

static int	ft_sizecalc(long nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	long	nb;

	nb = n;
	size = ft_sizecalc(nb);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_convert(str, nb, size);
	if (n < 0)
		str[0] = '-';
	return (str);
}
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(432));
	printf("%s\n", ft_itoa(-432));
}
