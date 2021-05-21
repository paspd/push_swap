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

int		check_is_pack(t_list *list, int div, int pack, t_struct *data)
{
	while (list != NULL)
	{
		if ((data->max_rank / div) * (pack - 1) < list->rank && list->rank <= (data->max_rank / div) * pack)
			return (1);
		list = list->next;
	}
	return (0);
}

void	bestsort(t_struct *data)
{
	int	div;
	int	pack;

	if (data->nb_a <= 100)
		div = 4;
	else if (data->nb_a <= 500)
		div = 10;
	pack = 0;
	while (!check_sort(data))
	{
		pack++;
		while (data->nb_a)
		{
			if (!check_is_pack(data->list_a, div, pack, data))
				pack++;
			if ((data->max_rank / div) * (pack - 1) < data->list_a->rank && data->list_a->rank <= (data->max_rank / div) * pack)
				ft_putstr(pb(data));
			else
				ft_putstr(ra(data));
		}
		// exit(0);
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

void	start_sort(t_struct *data)
{
	if (!check_tri(data->list_a))
	{
		if (data->nb_a <= 2)
			tinysort(data);
		else if (data->nb_a <= 3)
			smolsort(data);
		else if (data->nb_a <= 5)
			mediumsort(data);
		else if (data->nb_a <= 50)
			dumbsort(data);
		else if (data->nb_a <= 75)
			ranksort(data);
		else
			bestsort(data);
	}
}

int	main(int ac, char *av[])
{
	t_struct	data;

	ft_bzero(&data, sizeof(t_struct));
	if (ac < 2)
		return (0);
	check_av(&data, av, ac);
	fill_list(&data, av);
	check_list(&data);
	data.sort_tab = find_sort(data.list_a, &data);
	rank_list(data.sort_tab, data.list_a, &data);
	start_sort(&data);
	clean_data(&data);
	return (0);
}
