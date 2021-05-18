#include "push_swap.h"

int	check_first_quarter_rank(t_list *list, t_struct *data)
{
	while (list != NULL)
	{
		if (list->rank <= data->max_rank / 4)
			return (1);
		list = list->next;
	}
	return (0);
}

int	check_second_quarter_rank(t_list *list, t_struct *data)
{
	while (list != NULL)
	{
		if (list->rank > data->max_rank / 4 && list->rank <= data->max_rank / 2)
			return (1);
		list = list->next;
	}
	return (0);
}

int	check_third_quarter_rank(t_list *list, t_struct *data)
{
	while (list != NULL)
	{
		if (list->rank > data->max_rank / 2 && \
			list->rank <= (data->max_rank / 4) * 3)
			return (1);
		list = list->next;
	}
	return (0);
}

int	check_fourth_quarter_rank(t_list *list, t_struct *data)
{
	while (list != NULL)
	{
		if (list->rank > (data->max_rank / 4) * 3)
			return (1);
		list = list->next;
	}
	return (0);
}
