#include "push_swap.h"

void	move_n_sort_third_quarter(t_struct *data)
{
	if (!data->nb_b)
		ft_putstr(pb(data));
	else if (check_is_in_fourth_quarter_rank(data->list_b->rank, data) && \
		data->list_a->rank > ft_lstlast(data->list_b)->rank)
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

void	sort_fourth_quarter(t_struct *data)
{
	int	i;

	while (check_fourth_quarter_rank(data->list_b, data))
	{
		if (check_is_in_fourth_quarter_rank(data->list_a->rank, data) && \
			data->list_b->rank > data->list_a->rank)
		{
			i = 0;
			while (check_is_in_fourth_quarter_rank(data->list_a->rank, data) \
				&& data->list_b->rank > data->list_a->rank)
			{
				i++;
				ft_putstr(ra(data));
			}
			ft_putstr(pa(data));
			while (i-- > 0)
				ft_putstr(rra(data));
		}
		else
			ft_putstr(pa(data));
	}
}

void	sort_third_quarter(t_struct *data)
{
	int	i;

	while (data->nb_b)
	{
		if (check_is_in_third_quarter_rank(data->list_a->rank, data) && \
			data->list_b->rank > data->list_a->rank)
		{
			i = 0;
			while (check_is_in_third_quarter_rank(data->list_a->rank, data) && \
				data->list_b->rank > data->list_a->rank)
			{
				i++;
				ft_putstr(ra(data));
			}
			ft_putstr(pa(data));
			if (!data->nb_b)
				i = 0;
			while (i-- > 0)
			{
				ft_putstr(rra(data));
			}
		}
		else
			ft_putstr(pa(data));
	}
}

void	sort_second_half(t_struct *data)
{
	while (check_second_half_rank(data->list_a, data))
	{
		if (check_is_in_fourth_quarter_rank(data->list_a->rank, data))
			move_n_sort_fourth_quarter(data);
		else if (check_is_in_third_quarter_rank(data->list_a->rank, data))
			move_n_sort_third_quarter(data);
		else
			ft_putstr(rra(data));
	}
	sort_fourth_quarter(data);
	sort_third_quarter(data);
}

void	ranksort(t_struct *data)
{
	sort_first_half(data);
	sort_second_half(data);
	while (!check_sort(data))
		ft_putstr(ra(data));
}
