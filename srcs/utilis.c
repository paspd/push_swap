#include "push_swap.h"

/////////////////////////////
//////      CLEAN      //////
/////////////////////////////

void	clean_data(t_struct *data)
{
	ft_lstclear(&data->list_a);
	ft_lstclear(&data->list_b);
	exit (0);
}

/////////////////////////////
//////      ERROR      //////
/////////////////////////////

void	error(t_struct *data)
{
	ft_lstclear(&data->list_a);
	ft_lstclear(&data->list_b);
	if (data->sort_tab)
		free(data->sort_tab);
	ft_putstr("Error\n");
	exit (-1);
}
