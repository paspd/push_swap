#include "push_swap.h"

int	check_ra_rra(t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		if (list->content == check_large(list))
			return (i);
		i++;
		list = list->next;
	}
	return (i);
}

int	check_is_pack(t_list *list, int div, int pack, t_struct *data)
{
	while (list != NULL)
	{
		if ((data->max_rank / div) * (pack - 1) < list->rank && \
			list->rank <= (data->max_rank / div) * pack)
			return (1);
		list = list->next;
	}
	return (0);
}

void	part_1(t_struct *data)
{
	while (data->nb_a)
	{
		if (!check_is_pack(data->list_a, data->div, data->pack, data))
			data->pack++;
		if ((data->max_rank / data->div) * (data->pack - 1) < \
			data->list_a->rank && data->list_a->rank <= \
				(data->max_rank / data->div) * data->pack)
			ft_putstr(pb(data));
		else
			ft_putstr(ra(data));
	}
}

void	bestsort(t_struct *data)
{
	if (data->nb_a <= 100)
		data->div = 4;
	else
		data->div = 10;
	while (!check_sort(data))
	{
		data->pack++;
		part_1(data);
		while (data->nb_b)
		{
			if (check_large(data->list_b) == data->list_b->content)
				ft_putstr(pa(data));
			else if (check_ra_rra(data->list_b) <= data->nb_b / 2)
				ft_putstr(rb(data));
			else
				ft_putstr(rrb(data));
		}
	}
}
