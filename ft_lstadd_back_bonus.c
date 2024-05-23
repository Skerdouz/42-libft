#include "libft.h"
#include <assert.h>


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = ft_lstlast(*lst);
	ptr->next = new;
}
