#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	//TODO: do this function
	ptr = *lst;
	while (ptr->next)
	{
		ptr = ;
		(*del)()
	}
	
}
