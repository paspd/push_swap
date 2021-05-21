#include "push_swap.h"

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
	while (1);
	clean_data(&data);
	return (0);
}
