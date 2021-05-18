#include "push_swap.h"

void	sort_first_half(t_struct *data)
{
	while (check_half_rank(data->list_a, data))
	{
		if (data->list_a->rank <= data->max_rank / 2)
			move_n_sort_first_half(data);
		else if (check_ra_rra_rank_inf(data->list_a, data, 2))
			ft_putstr(ra(data));
		else
			ft_putstr(rra(data));
	}
	while (check_second_quarter_rank(data->list_b, data))
	{
		if (data->list_b->rank > data->list_a->rank)
			sort_second_quarter(data);
		else
			ft_putstr(pa(data));
	}
	while (data->nb_b)
	{
		if (data->list_b->rank > data->list_a->rank)
			sort_first_quarter(data);
		else
			ft_putstr(pa(data));
	}
}

void	move_n_sort_fourth_quarter(t_struct *data)
{
	if (!data->nb_b)
		ft_putstr(pb(data));
	else if (data->list_a->rank < data->list_b->rank)
	{
		ft_putstr(pb(data));
		ft_putstr(sb(data));
	}
	else
		ft_putstr(pb(data));
}
