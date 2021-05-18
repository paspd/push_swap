#include "../../incs/libft.h"

void	ft_dellst_one(t_list **list, int i)
{
	t_list	*tmp;
	t_list	*ptmp;
    int     limit;

    limit = 1;
	if (*list == NULL)
		return ;
	if (ft_lstsize(*list) < i)
		return ;
	if ((*list)->next == NULL)
	{
		free(*list);
		*list = NULL;
		return ;
	}
	tmp = *list;
	ptmp = *list;
	while (limit != i && tmp->next != NULL)
	{
		ptmp = tmp;
		tmp = tmp->next;
		limit++;
	}
	ptmp->next = tmp->next;
	if (tmp->next == NULL)
		ptmp->next = NULL;
	free(tmp);
}