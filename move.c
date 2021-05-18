#include "push_swap.h"

char	*sa(t_struct *data)
{
	if (data->nb_a >= 2)
	{
		ft_lstadd_front(&data->list_a, ft_lstn(data->list_a, 2)->content);
		data->list_a->rank = ft_lstn(data->list_a, 3)->rank;
		ft_dellst_one(&data->list_a, 3);
        data->nb_move++;
        return("sa\n");
	}
	return (0);
}

char	*sb(t_struct *data)
{
	if (data->nb_b >= 2)
	{
		ft_lstadd_front(&data->list_b, ft_lstn(data->list_b, 2)->content);
		data->list_b->rank = ft_lstn(data->list_b, 3)->rank;
		ft_dellst_one(&data->list_b, 3);
        data->nb_move++;
        return("sb\n");
	}
	return (0);
}

char	*ss(t_struct *data)
{
	if (data->nb_a >= 2 && data->nb_b >= 2)
	{
		ft_lstadd_front(&data->list_a, ft_lstn(data->list_a, 2)->content);
		ft_lstadd_front(&data->list_b, ft_lstn(data->list_b, 2)->content);
		data->list_a->rank = ft_lstn(data->list_a, 3)->rank;
		data->list_b->rank = ft_lstn(data->list_b, 3)->rank;
		ft_dellst_one(&data->list_a, 3);
		ft_dellst_one(&data->list_b, 3);
        data->nb_move++;
        return("ss\n");
	}
	return (0);
}

char	*pa(t_struct *data)
{
	if (data->nb_b)
	{
		ft_lstadd_front(&data->list_a, ft_lstn(data->list_b, 1)->content);
		data->list_a->rank = data->list_b->rank;
		ft_dellst_front(&data->list_b);
		data->nb_a++;
		data->nb_b--;
        data->nb_move++;
        return("pa\n");
	}
	return (0);
}

char	*pb(t_struct *data)
{
	if (data->nb_a)
	{
		ft_lstadd_front(&data->list_b, ft_lstn(data->list_a, 1)->content);
		data->list_b->rank = data->list_a->rank;
		ft_dellst_front(&data->list_a);
		data->nb_a--;
		data->nb_b++;
        data->nb_move++;
        return("pb\n");
	}
	return (0);
}

char	*ra(t_struct *data)
{
	if (data->nb_a)
	{
		ft_lstadd_back(&data->list_a, ft_lstn(data->list_a, 1)->content);
		ft_lstlast(data->list_a)->rank = data->list_a->rank;
		ft_dellst_front(&data->list_a);
        data->nb_move++;
		data->nb_ra++;
        return("ra\n");
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
        return("rb\n");
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
        return("rr\n");
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
        return("rra\n");
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
        return("rrb\n");
	}
	return (0);
}

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
        return("rrr\n");
	}
	return (0);
}
