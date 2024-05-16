#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*pdest;
	char	*psrc;

	pdest = (char *)dest;
	psrc = (char *)src;
	while (i < n)
		pdest[i] = psrc[i++];
	return (dest);
}
