#include "push_swap.h"

int	check_is_in_first_quarter_rank(int value, t_struct *data)
{
	if (value <= data->max_rank / 4)
		return (1);
	return (0);
}

int	check_is_in_second_quarter_rank(int value, t_struct *data)
{
	if (value > data->max_rank / 4 && value <= data->max_rank / 2)
		return (1);
	return (0);
}

int	check_is_in_third_quarter_rank(int value, t_struct *data)
{
	if (value <= (data->max_rank / 4) * 3 && value > data->max_rank / 2)
		return (1);
	return (0);
}

int	check_is_in_fourth_quarter_rank(int value, t_struct *data)
{
	if (value > (data->max_rank / 4) * 3)
		return (1);
	return (0);
}
