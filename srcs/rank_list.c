#include "push_swap.h"

int	*sort_tab(int *sort, int size)
{
	int	i;

	i = 0;
	if (size == 1)
		return (sort);
	while (i < size)
	{
		if (sort[i] > sort[i + 1])
		{
			ft_swap(&sort[i], &sort[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	return (sort);
}

void	rank_list(int *tab, t_list *list, t_struct *data)
{
	int	i_l;

	while (list != NULL)
	{
		i_l = 0;
		while (list->content != tab[i_l])
			i_l++;
		list->rank = i_l + 1;
		list = list->next;
	}
	data->max_rank = data->nb_a;
}

/////////////////////////////
//////    FIND_SORT    //////
/////////////////////////////

int	*find_sort(t_list *list, t_struct *data)
{
	int	i;
	int	*temp;

	i = 0;
	temp = ft_calloc(ft_lstsize(list), sizeof(int));
	if (!temp)
		error(data);
	while (list->next != NULL)
	{
		temp[i++] = list->content;
		list = list->next;
	}
	temp[i] = list->content;
	temp = sort_tab(temp, i);
	return (temp);
}
