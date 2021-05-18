#include "push_swap.h"

void	fill_list(t_struct *d, char **av)
{
	d->fl.i = 1;
	d->fl.neg = 1;
	while (av[d->fl.i])
	{
		d->fl.j = 0;
		d->fl.temp = 0;
		while (av[d->fl.i][d->fl.j])
		{
			if (av[d->fl.i][d->fl.j] == '-')
				d->fl.neg *= -1;
			if (av[d->fl.i][d->fl.j] == '-')
				d->fl.j++;
			while (ft_isdigit(av[d->fl.i][d->fl.j]))
				d->fl.temp = d->fl.temp * 10 + (av[d->fl.i][d->fl.j++] - 48);
			while (!ft_isdigit(av[d->fl.i][d->fl.j]) \
				&& av[d->fl.i][d->fl.j] != '-' && av[d->fl.i][d->fl.j])
				d->fl.j++;
			ft_lstadd_back(&d->list_a, d->fl.temp * d->fl.neg);
			d->fl.temp = 0;
			d->fl.neg = 1;
			d->nb_int++;
		}
		d->fl.i++;
	}
	d->nb_a = d->nb_int;
}
