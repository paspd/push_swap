#include "push_swap.h"

//Si la taille == 3, tri seulement les 3 premiers nombres de la liste a
void	smolsort(t_struct *data)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = data->list_a->content;
	n2 = data->list_a->next->content;
	n3 = data->list_a->next->next->content;
	if (n1 < n2 && n2 > n3 && n1 > n3)
		ft_putstr(rra(data));
	else if (n1 > n2 && n2 < n3 && n1 < n3)
		ft_putstr(sa(data));
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ft_putstr(ra(data));
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		ft_putstr(rra(data));
		ft_putstr(sa(data));
	}
	else if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		ft_putstr(ra(data));
		ft_putstr(sa(data));
	}
}

void	tinysort(t_struct *data)
{
	if (data->list_a->content > data->list_a->next->content)
		ft_putstr(sa(data));
}

//Si la taille == 4 || 5, tri les 5 premiers nombres de la liste a
void	mediumsort(t_struct *data)
{
	if (data->nb_a == 5)
		ft_putstr(pb(data));
	if (data->nb_a == 4)
		ft_putstr(pb(data));
	smolsort(data);
	if (data->nb_b == 2)
		if (data->list_b->content > data->list_b->next->content)
			ft_putstr(sa(data));
	while (data->nb_b)
	{
		if (data->list_b->content > ft_lstlast(data->list_a)->content)
		{
			ft_putstr(rra(data));
			ft_putstr(pa(data));
			ft_putstr(ra(data));
		}
		else if (data->list_b->content < data->list_a->content)
			ft_putstr(pa(data));
		else
			ft_putstr(ra(data));
	}
}

//Algorithme de tri basique (ra/rra)
void	dumbsort(t_struct *data)
{
	if (check_sort(data))
		return ;
	if (data->nb_a > 3)
	{
		if (data->list_a->content == check_tiny(data->list_a))
			ft_putstr(pb(data));
		else if (check_index_tiny(data->list_a) <= data->nb_a / 2)
			ft_putstr(ra(data));
		else
			ft_putstr(rra(data));
	}
	if (data->nb_a == 3)
		smolsort(data);
	if (data->nb_a == 3)
		while (data->nb_b)
			ft_putstr(pa(data));
	dumbsort(data);
}
