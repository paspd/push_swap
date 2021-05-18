#include "../../incs/libft.h"

void	ft_dellst_front(t_list **list)
{
	t_list	*tmp;

	if (list == NULL)
		return ;
	tmp = (*list)->next;
	free(*list);
	*list = tmp;
}