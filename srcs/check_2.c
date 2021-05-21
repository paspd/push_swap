#include "push_swap.h"

//Return 1 si le nombre est un des trois plus petit de la list a
int	check_is_tiny(t_struct *data, int value)
{
	int	i;
	int	limit;

	i = data->nb_b - (data->nb_b % 3);
	limit = i + 3;
	while (i < limit)
	{
		if (value == data->sort_tab[i])
			return (1);
		i++;
	}
	return (0);
}

//Return le plus petit int de la list
int	check_tiny(t_list *list)
{
	int	smallest;

	smallest = list->content;
	while (list->next != NULL)
	{
		if (list->content < smallest)
			smallest = list->content;
		list = list->next;
	}
	if (list->content < smallest)
		smallest = list->content;
	return (smallest);
}

//Return le plus petit int de la list
int	check_large(t_list *list)
{
	int	largest;

	largest = list->content;
	while (list->next != NULL)
	{
		if (list->content > largest)
			largest = list->content;
		list = list->next;
	}
	if (list->content > largest)
		largest = list->content;
	return (largest);
}

//Return l'index du plus petit int de la list
int	check_index_tiny(t_list *list)
{
	int	smallest;
	int	index;
	int	index_tiny;

	index = 1;
	smallest = list->content;
	while (list != NULL)
	{
		if (list->content < smallest)
			index_tiny = index;
		if (list->content < smallest)
			smallest = list->content;
		list = list->next;
		index++;
	}
	return (index_tiny);
}

int	check_ra_rra_rank_inf(t_list *list, t_struct *data, int div)
{
	int	start_rank;
	int	end_rank;
	int	i;

	i = 1;
	start_rank = 0;
	end_rank = 0;
	while (list != NULL)
	{
		if (list->rank <= data->max_rank / div)
		{
			if (!start_rank)
				start_rank = i;
			else
				end_rank = i;
		}
		i++;
		list = list->next;
	}
	if (end_rank && i - end_rank < start_rank - 1)
		return (0);
	else if (start_rank > i / 2)
		return (0);
	return (1);
}
