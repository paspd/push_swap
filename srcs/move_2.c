#include "push_swap.h"

char	*ra(t_struct *data)
{
	if (data->nb_a)
	{
		ft_lstadd_back(&data->list_a, ft_lstn(data->list_a, 1)->content);
		ft_lstlast(data->list_a)->rank = data->list_a->rank;
		ft_dellst_front(&data->list_a);
		data->nb_move++;
		data->nb_ra++;
		return ("ra\n");
	}
	return (0);
}

char	*rb(t_struct *data)
{
	if (data->nb_b)
	{
		ft_lstadd_back(&data->list_b, ft_lstn(data->list_b, 1)->content);
		ft_lstlast(data->list_b)->rank = data->list_b->rank;
		ft_dellst_front(&data->list_b);
		data->nb_move++;
		return ("rb\n");
	}
	return (0);
}

char	*rr(t_struct *data)
{
	if (data->nb_a && data->nb_b)
	{
		ft_lstadd_back(&data->list_a, ft_lstn(data->list_a, 1)->content);
		ft_lstadd_back(&data->list_b, ft_lstn(data->list_b, 1)->content);
		ft_lstlast(data->list_a)->rank = data->list_a->rank;
		ft_lstlast(data->list_b)->rank = data->list_b->rank;
		ft_dellst_front(&data->list_a);
		ft_dellst_front(&data->list_b);
		data->nb_move++;
		return ("rr\n");
	}
	return (0);
}

char	*rra(t_struct *data)
{
	if (data->nb_a)
	{
		ft_lstadd_front(&data->list_a, ft_lstlast(data->list_a)->content);
		data->list_a->rank = ft_lstlast(data->list_a)->rank;
		ft_dellst_back(&data->list_a);
		data->nb_move++;
		data->nb_rra++;
		return ("rra\n");
	}
	return (0);
}

char	*rrb(t_struct *data)
{
	if (data->nb_b)
	{
		ft_lstadd_front(&data->list_b, ft_lstlast(data->list_b)->content);
		data->list_b->rank = ft_lstlast(data->list_b)->rank;
		ft_dellst_back(&data->list_b);
		data->nb_move++;
		return ("rrb\n");
	}
	return (0);
}
