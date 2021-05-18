#include "push_swap.h"

char	*rrr(t_struct *data)
{
	if (data->nb_a && data->nb_b)
	{
		ft_lstadd_front(&data->list_a, ft_lstlast(data->list_a)->content);
		ft_lstadd_front(&data->list_b, ft_lstlast(data->list_b)->content);
		data->list_a->rank = ft_lstlast(data->list_a)->rank;
		data->list_b->rank = ft_lstlast(data->list_b)->rank;
		ft_dellst_back(&data->list_a);
		ft_dellst_back(&data->list_b);
		data->nb_move++;
		return ("rrr\n");
	}
	return (0);
}
