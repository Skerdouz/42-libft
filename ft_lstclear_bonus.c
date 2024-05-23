#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr->next)
	{
		ptr = ;
		(*del)()
	}
	
}
