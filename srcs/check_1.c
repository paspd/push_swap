#include "push_swap.h"

//Check arguments
void	check_av(t_struct *data, char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while ((ft_isdigit(av[i][j]) || av[i][j] == '-' || \
			(ac == 2 && av[i][j] == ' ')) && av[i][j])
			j++;
		if (av[i][j])
			error(data);
		i++;
	}
}

//Check doublons
void	check_list(t_struct *data)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i <= data->nb_a)
	{
		temp = ft_lstn(data->list_a, i)->content;
		j = 1;
		while (j <= data->nb_a)
		{
			if (temp == ft_lstn(data->list_a, j)->content && i != j)
				error(data);
			j++;
		}
		i++;
	}
}

//Return 1 si la liste est trié sinon 0
int	check_tri(t_list *list)
{
	while (list->next != NULL)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

//Return 1 si la liste est trié du plus grand au plus petit sinon 0
int	check_unsort(t_list *list)
{
	if (list == NULL)
		return (1);
	while (list->next != NULL)
	{
		if (list->content < list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

//Return 1 si la liste b est vide et que la liste a est trié sinon 0
int	check_sort(t_struct *data)
{
	if (data->nb_b)
		return (0);
	if (!check_tri(data->list_a))
		return (0);
	return (1);
}
