#include "push_swap.h"

int	check_half_rank(t_list *list, t_struct *data)
{
	while (list != NULL)
	{
		if (list->rank <= data->max_rank / 2)
			return (1);
		list = list->next;
	}
	return (0);
}

int	check_second_half_rank(t_list *list, t_struct *data)
{
	while (list != NULL)
	{
		if (list->rank > data->max_rank / 2)
			return (1);
		list = list->next;
	}
	return (0);
}
