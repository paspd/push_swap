#include "push_swap.h"

void	move_n_sort_first_half(t_struct *data)
{
	if (!data->nb_b)
		ft_putstr(pb(data));
	else if (data->list_a->rank > data->max_rank / 4)
	{
		if (data->list_a->rank > data->list_b->rank)
			ft_putstr(pb(data));
		else
		{
			ft_putstr(rb(data));
			ft_putstr(pb(data));
			ft_putstr(rrb(data));
		}
	}
	else if (data->list_a->rank > ft_lstlast(data->list_b)->rank)
	{
		ft_putstr(rrb(data));
		ft_putstr(pb(data));
		ft_putstr(rb(data));
		ft_putstr(rb(data));
	}
	else
	{
		ft_putstr(pb(data));
		ft_putstr(rb(data));
	}
}

void	second_while_of_second_quarter(t_struct *data)
{
	while (check_is_in_second_quarter_rank(data->list_b->rank, data) && \
		data->list_b->rank > ft_lstlast(data->list_a)->rank && \
			data->list_b->rank < data->list_a->rank)
		ft_putstr(pa(data));
	while (check_is_in_second_quarter_rank(data->list_b->next->rank, data) && \
		data->list_b->next->rank > ft_lstlast(data->list_a)->rank && \
			data->list_b->next->rank < data->list_a->rank)
	{
		ft_putstr(sb(data));
		ft_putstr(pa(data));
	}
	ft_putstr(rra(data));
}

void	sort_second_quarter(t_struct *data)
{
	int	i;

	i = 0;
	while (data->list_b->rank > data->list_a->rank)
	{
		i++;
		while (check_is_in_second_quarter_rank(data->list_b->next->rank, data) && \
			data->list_b->next->rank > ft_lstlast(data->list_a)->rank && \
				data->list_b->next->rank < data->list_a->rank)
		{
			ft_putstr(sb(data));
			ft_putstr(pa(data));
		}
		ft_putstr(ra(data));
	}
	ft_putstr(pa(data));
	while (i-- > 0)
		second_while_of_second_quarter(data);
}

void	second_while_of_first_quarter(t_struct *data)
{
	while (data->list_b->rank > ft_lstlast(data->list_a)->rank && \
		data->list_b->rank < data->list_a->rank)
		ft_putstr(pa(data));
	while (data->nb_b > 1 && data->list_b->next->rank > ft_lstlast(data->list_a)->rank && \
		data->list_b->next->rank < data->list_a->rank)
	{
		ft_putstr(sb(data));
		ft_putstr(pa(data));
	}
	ft_putstr(rra(data));
}

void	sort_first_quarter(t_struct *data)
{
	int	i;

	i = 0;
	while (data->list_b->rank > data->list_a->rank)
	{
		while (data->list_b->next->rank > ft_lstlast(data->list_a)->rank && \
			data->list_b->next->rank < data->list_a->rank)
		{
			ft_putstr(sb(data));
			ft_putstr(pa(data));
		}
		ft_putstr(ra(data));
		i++;
	}
	ft_putstr(pa(data));
	while (i-- > 0)
		second_while_of_first_quarter(data);
}
