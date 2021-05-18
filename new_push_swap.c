#include "push_swap.h"

/////////////////////////////
//////      CLEAN      //////
/////////////////////////////

void	clean_data(t_struct *data)
{
	ft_lstclear(&data->list_a);
	ft_lstclear(&data->list_b);
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

/////////////////////////////
//////     AFF_LIST    //////
/////////////////////////////


void	aff_lists(t_struct *data)
{
	char *color_a = "\033[32m";
	char *color_b = "\033[38;5;128m";
	char *color_0 = "\033[0m";
	printf("%sLISTE A:\n	%s", color_a, color_0);
	ft_lstaff_color(data->list_a, color_a);
	printf("%sLISTE B:\n	%s", color_b, color_0);
	ft_lstaff_color(data->list_b, color_b);
}

int *sort_tab(int *sort, int size)
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

int *find_sort(t_list *list, t_struct *data)
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

/////////////////////////////
//////    FILL_LIST    //////
/////////////////////////////

void	fill_list(t_struct *data, char **av)
{
	data->fl.i = 1;
	data->fl.neg = 1;
	while (av[data->fl.i])
	{
		data->fl.j = 0;
		data->fl.temp = 0;
		while (av[data->fl.i][data->fl.j])
		{
			if (av[data->fl.i][data->fl.j] == '-')
				data->fl.neg *= -1;
			if (av[data->fl.i][data->fl.j] == '-')
				data->fl.j++;
			while (ft_isdigit(av[data->fl.i][data->fl.j]))
				data->fl.temp = data->fl.temp * 10 + (av[data->fl.i][data->fl.j++] - 48);
			while (!ft_isdigit(av[data->fl.i][data->fl.j]) \
				&& av[data->fl.i][data->fl.j] != '-' && av[data->fl.i][data->fl.j])
				data->fl.j++;
			ft_lstadd_back(&data->list_a, data->fl.temp * data->fl.neg);
			data->fl.temp = 0;
			data->fl.neg = 1;
			data->nb_int++;
		}
		data->fl.i++;
	}
	data->nb_a = data->nb_int;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////          DEBUT FONCTIONS DE CHECK          ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

//Check arguments
void	check_av(t_struct *data, char **av, int ac)
{
	int	i;
	int j;

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
	int i;
	int j;
	int temp;

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

//Return 1 si le nombre est un des trois plus petit de la list a
int	check_is_tiny(t_struct *data, int value)
{
	int i;
	int limit;

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

int	check_half(int n1, int n2, int n3, int size)
{
	int	ra;
	int	rra;

	ra = 0;
	rra = 0;
	if (n1 && n1 > size / 2)
		rra++;
	if (n3 && n3 <= size / 2)
		ra++;
	else if (n2 && n2 <= size / 2)
		ra++;
	else if (n2 && n2 > size / 2)
		rra++;
	if (n3 && n1 && size - n3 < n1)
		rra++;
	if (n3 && n3 <= size / 3)
		ra += 2;
	if (n3 && n3 >= (size / 5) * 4)
		rra += 2;
	if (n1 >= (size / 5) * 4)
		rra += 2;
	if (n1 <= size / 5)
		ra += 2;
	if (n3 && size - n3 < n1)
		rra++;
	else if (!n3)
	{
		if (n2 && n1 && size - n2 < n1)
			rra++;
	}
	else
		ra++;
	if (ra > rra)
		return (1); //RA
	return (0); //RRA
}

int	check_ra_rra(t_struct *data)
{
	int i;
	int	i_1;
	int	i_2;
	int	i_3;

	i = 1;
	i_1 = 0;
	i_2 = 0;
	i_3 = 0;
	while (i <= data->nb_a)
	{
		if (check_is_tiny(data, ft_lstn(data->list_a, i)->content))
		{	
			if (!i_1)
				i_1 = i;
			else if (!i_2)
				i_2 = i;
			else if (!i_3)
				i_3 = i;
		}
		i++;
	}
	return (check_half(i_1, i_2, i_3, data->nb_a));
}

//Return le plus petit int de la list
int		check_tiny(t_list *list)
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

int		check_half_rank(t_list *list, t_struct *data)
{
	while (list != NULL)
	{
		if (list->rank <= data->max_rank / 2)
			return (1);
		list = list->next;
	}
	return (0);
}

int		check_second_half_rank(t_list *list, t_struct *data)
{
	while (list != NULL)
	{
		if (list->rank > data->max_rank / 2)
			return (1);
		list = list->next;
	}
	return (0);
}

int		check_first_quarter_rank(t_list *list, t_struct *data)
{
	while (list != NULL)
	{
		if (list->rank <= data->max_rank / 4)
			return (1);
		list = list->next;
	}
	return (0);
}

int		check_is_in_first_quarter_rank(int value, t_struct *data)
{
	if (value <= data->max_rank / 4)
		return (1);
	return (0);
}

int		check_is_in_second_quarter_rank(int value, t_struct *data)
{
	if (value > data->max_rank / 4 && value <= data->max_rank / 2)
		return (1);
	return (0);
}

int		check_is_in_third_quarter_rank(int value, t_struct *data)
{
	if (value <= (data->max_rank / 4) * 3 && value > data->max_rank / 2)
		return (1);
	return (0);
}

int		check_is_in_fourth_quarter_rank(int value, t_struct *data)
{
	if (value > (data->max_rank / 4) * 3)
		return (1);
	return (0);
}

int		check_second_quarter_rank(t_list *list, t_struct *data)
{
	while (list != NULL)
	{
		if (list->rank > data->max_rank / 4 && list->rank <= data->max_rank / 2)
			return (1);
		list = list->next;
	}
	return (0);
}

int		check_third_quarter_rank(t_list *list, t_struct *data)
{
	while (list != NULL)
	{
		if (list->rank > data->max_rank / 2 && list->rank <= (data->max_rank / 4) * 3)
			return (1);
		list = list->next;
	}
	return (0);
}

int		check_fourth_quarter_rank(t_list *list, t_struct *data)
{
	while (list != NULL)
	{
		if (list->rank > (data->max_rank / 4) * 3)
			return (1);
		list = list->next;
	}
	return (0);
}

int		check_third_quarter_rank_sort(t_list *list, t_struct *data)
{
	int	temp;

	temp = 0;
	while (list != NULL)
	{
		if (check_is_in_third_quarter_rank(list->rank, data))
		{
			if (!temp)
				temp = list->rank;
			else if (temp > list->rank)
				return (0);
			else
				temp = list->rank;
		}
		list = list->next;
	}
	return (1);
}

int		check_ra_rra_rank_inf(t_list *list, t_struct *data, int div)
{
	int	start_rank;
	int	end_rank;
	int i;

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

int		check_ra_rra_rank_sup(t_list *list, t_struct *data, int div)
{
	int	start_rank;
	int	end_rank;
	int i;

	i = 1;
	start_rank = 0;
	end_rank = 0;
	while (list != NULL)
	{
		if (list->rank < data->max_rank / div)
		{
			if (!start_rank)
				start_rank = i;
			else
				end_rank = i;
		}
		i++;
		list = list->next;
	}
	if (i - end_rank < start_rank - 1)
		return (0);
	return (1);
}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////            FIN FONCTIONS DE CHECK          ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////           DEBUT FONCTIONS DE TRI           ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void	topsort(t_struct *data)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = data->list_b->content;
	n2 = data->list_b->next->content;
	n3 = data->list_b->next->next->content;
	if (n1 < n2 && n2 < n3 && n1 < n3)
	{
		ft_putstr(rb(data));
		ft_putstr(sb(data));
		ft_putstr(rrb(data));
		ft_putstr(sb(data));
		ft_putstr(rb(data));
		ft_putstr(sb(data));
		ft_putstr(rrb(data));
	}
	if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		ft_putstr(sb(data));
		ft_putstr(rb(data));
		ft_putstr(sb(data));
		ft_putstr(rrb(data));
	}
	if (n1 > n2 && n2 < n3 && n1 < n3)
	{
		ft_putstr(rb(data));
		ft_putstr(sb(data));
		ft_putstr(rrb(data));
		ft_putstr(sb(data));
	}
	if (n1 < n2 && n2 > n3 && n1 > n3)
		ft_putstr(sb(data));
	if (n1 > n2 && n2 < n3 && n1 > n3)
	{
		ft_putstr(rb(data));
		ft_putstr(sb(data));
		ft_putstr(rrb(data));
	}
	data->check_tiny += 3;
}

//Tri seulement les 2 premiers nombres de la liste a
void	tinysort(t_struct *data)
{
	if (data->list_a->content > data->list_a->next->content)
		ft_putstr(sa(data));
}

//Si la taille == 3, tri seulement les 3 premiers nombres de la liste b
void	smolsort_b(t_struct *data)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = data->list_b->content;
	n2 = data->list_b->next->content;
	n3 = data->list_b->next->next->content;
	if (n1 < n2 && n2 > n3 && n1 > n3)
		ft_putstr(rrb(data));
	else if (n1 > n2 && n2 < n3 && n1 < n3)
		ft_putstr(sb(data));
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ft_putstr(rb(data));
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		ft_putstr(rrb(data));
		ft_putstr(sb(data));
	}
	else if (n1 > n2 && n2 > n3 && n1 > n3)
	{

		ft_putstr(rb(data));
		ft_putstr(sb(data));
	}
}

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

void	voidsort(t_struct *data)
{
	if (check_sort(data))
		return ;
	if ((data->nb_b % 3) == 0 && !check_unsort(data->list_b))
		topsort(data);
	else if (data->nb_a <= 3 && (data->nb_b % 3) == 0)
	{
		topsort(data);
		if (data->nb_a == 3)
			smolsort(data);
		else if (data->nb_a == 2)
			tinysort(data);
		while (data->nb_b)
			ft_putstr(pa(data));
	}
	else if (check_is_tiny(data, data->list_a->content))
		ft_putstr(pb(data));
	else if (check_ra_rra(data))
		ft_putstr(ra(data));
	else
		ft_putstr(rra(data));
	voidsort(data);
}

void	move_n_sort_first_half(t_struct *data)
{
	if (!data->nb_b)
		ft_putstr(pb(data));
	else if (data->list_a->rank > data->max_rank / 4)
	{
		if (data->list_a->rank > data->list_b->rank)
			ft_putstr(pb(data));
		else
		{
			ft_putstr(rb(data));
			ft_putstr(pb(data));
			ft_putstr(rrb(data));
		}
	}
	else if (data->list_a->rank > ft_lstlast(data->list_b)->rank)
	{
			ft_putstr(rrb(data));
			ft_putstr(pb(data));
			ft_putstr(rb(data));
			ft_putstr(rb(data));
	}
	else
	{
		ft_putstr(pb(data));
		ft_putstr(rb(data));
	}
}

void	sort_second_quarter(t_struct *data)
{
	int i;

	i = 0;
	while (data->list_b->rank > data->list_a->rank)
	{
		i++;
		while (check_is_in_second_quarter_rank(data->list_b->next->rank, data) && data->list_b->next->rank > ft_lstlast(data->list_a)->rank && data->list_b->next->rank < data->list_a->rank)
		{
			ft_putstr(sb(data));
			ft_putstr(pa(data));
		}
		ft_putstr(ra(data));
	}
	ft_putstr(pa(data));
	while (i-- > 0)
	{
		while (check_is_in_second_quarter_rank(data->list_b->rank, data) && data->list_b->rank > ft_lstlast(data->list_a)->rank && data->list_b->rank < data->list_a->rank)
			ft_putstr(pa(data));
		while (check_is_in_second_quarter_rank(data->list_b->next->rank, data) && data->list_b->next->rank > ft_lstlast(data->list_a)->rank && data->list_b->next->rank < data->list_a->rank)
		{
			ft_putstr(sb(data));
			ft_putstr(pa(data));
		}
		ft_putstr(rra(data));
	}
}

void	sort_first_quarter(t_struct *data)
{
	int i;

	i = 0;
	while (data->list_b->rank > data->list_a->rank)
	{
		while (data->list_b->next->rank > ft_lstlast(data->list_a)->rank && data->list_b->next->rank < data->list_a->rank)
		{
			ft_putstr(sb(data));
			ft_putstr(pa(data));
		}
		ft_putstr(ra(data));
		i++;
	}
	ft_putstr(pa(data));
	while (i-- > 0)
	{
		while (data->list_b->rank > ft_lstlast(data->list_a)->rank && data->list_b->rank < data->list_a->rank)
			ft_putstr(pa(data));
		while (data->nb_b > 1 && data->list_b->next->rank > ft_lstlast(data->list_a)->rank && data->list_b->next->rank < data->list_a->rank)
		{
			ft_putstr(sb(data));
			ft_putstr(pa(data));
		}
		ft_putstr(rra(data));
	}
}

void	sort_first_half(t_struct *data)
{
	while (check_half_rank(data->list_a, data))
	{
		if (data->list_a->rank <= data->max_rank / 2)
			move_n_sort_first_half(data);
		else if (check_ra_rra_rank_inf(data->list_a, data, 2))
			ft_putstr(ra(data));
		else
			ft_putstr(rra(data));
	}
	while (check_second_quarter_rank(data->list_b, data))
	{
		if (data->list_b->rank > data->list_a->rank)
			sort_second_quarter(data);			
		else
			ft_putstr(pa(data));
	}
	while (data->nb_b)
	{
		if (data->list_b->rank > data->list_a->rank)
				sort_first_quarter(data);
		else 
			ft_putstr(pa(data));
	}
}

void	move_n_sort_fourth_quarter(t_struct *data)
{
	if (!data->nb_b)
		ft_putstr(pb(data));
	else if (data->list_a->rank < data->list_b->rank)
	{
		ft_putstr(pb(data));
		ft_putstr(sb(data));
	}
	else
		ft_putstr(pb(data));
}

void	move_n_sort_third_quarter(t_struct *data)
{
	if (!data->nb_b)
		ft_putstr(pb(data));
	else if (check_is_in_fourth_quarter_rank(data->list_b->rank, data) && data->list_a->rank > ft_lstlast(data->list_b)->rank)
	{
		ft_putstr(rrb(data));
		ft_putstr(pb(data));
		ft_putstr(rb(data));
		ft_putstr(rb(data));
	}
	else
	{
		ft_putstr(pb(data));
		ft_putstr(rb(data));
	}
}

void	sort_fourth_quarter(t_struct *data)
{
	int i;

	while (check_fourth_quarter_rank(data->list_b, data))
	{
		if (check_is_in_fourth_quarter_rank(data->list_a->rank, data) && data->list_b->rank > data->list_a->rank)
		{
			i = 0;
			while (check_is_in_fourth_quarter_rank(data->list_a->rank, data) && data->list_b->rank > data->list_a->rank)
			{
				i++;
				ft_putstr(ra(data));
			}
			ft_putstr(pa(data));
			while (i-- > 0)
				ft_putstr(rra(data));
		}
		else
			ft_putstr(pa(data));
	}
}

void	sort_third_quarter(t_struct *data)
{
	int	i;

	while (data->nb_b)
	{
		if (check_is_in_third_quarter_rank(data->list_a->rank, data) && data->list_b->rank > data->list_a->rank)
		{
			i = 0;
			while (check_is_in_third_quarter_rank(data->list_a->rank, data) && data->list_b->rank > data->list_a->rank)
			{
				i++;
				ft_putstr(ra(data));
			}
			ft_putstr(pa(data));
			if (!data->nb_b)
				i = 0;
			while (i-- > 0)
			{
				ft_putstr(rra(data));
			}
		}
		else
			ft_putstr(pa(data));
	}
}

void	sort_second_half(t_struct *data)
{
	while (check_second_half_rank(data->list_a, data))
	{
		if (check_is_in_fourth_quarter_rank(data->list_a->rank, data))
			move_n_sort_fourth_quarter(data);
		else if (check_is_in_third_quarter_rank(data->list_a->rank, data))
			move_n_sort_third_quarter(data);
		else
			ft_putstr(rra(data));
	}
	sort_fourth_quarter(data);
	sort_third_quarter(data);
}

void	ranksort(t_struct *data)
{
	sort_first_half(data);
	sort_second_half(data);
	while (!check_sort(data))
		ft_putstr(ra(data));
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
		else if (data->nb_a <= 55)
			voidsort(data);
		else
			ranksort(data);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////             FIN FONCTIONS DE TRI           ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////



int main(int ac, char *av[])
{
	t_struct data;

	ft_bzero(&data, sizeof(t_struct));
	if (ac < 2)
		return (0);
	check_av(&data, av, ac);
	fill_list(&data, av);
	// aff_lists(&data);
	check_list(&data);
	data.sort_tab = find_sort(data.list_a, &data);
	rank_list(data.sort_tab, data.list_a, &data);
	start_sort(&data);
	// aff_lists(&data);
	// printf("Nombres de mouvement :%d\n", data.nb_move);
	// printf("max_rank :%d\n", data.max_rank);
	// printf("nb_a :%d\n", data.nb_a);
	// printf("nb_ra :%d | nb_rra :%d |\n", data.nb_ra, data.nb_rra);
	clean_data(&data);
	return 0;
}