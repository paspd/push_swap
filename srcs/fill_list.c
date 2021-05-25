#include "push_swap.h"

void	fill_list(t_struct *d, char **av)
{
	long int	temp;

	d->fl.i = 0;
	while (av[++d->fl.i])
	{
		d->fl.j = 0;
		while (av[d->fl.i][d->fl.j])
		{
			temp = 0;
			d->fl.neg = 1;
			while (!ft_ischar("0123456789-", av[d->fl.i][d->fl.j]))
				d->fl.j++;
			if (av[d->fl.i][d->fl.j] == '-')
				d->fl.neg *= -1;
			if (av[d->fl.i][d->fl.j] == '-')
				d->fl.j++;
			while (ft_ischar("0123456789", av[d->fl.i][d->fl.j]))
				temp = temp * 10 + (av[d->fl.i][d->fl.j++] - 48);
			if (temp < -2147483648 || temp > 2147483647)
				error(d);
			ft_lstadd_back(&d->list_a, (int)(temp * d->fl.neg));
			d->nb_a++;
		}
	}
	d->nb_int = d->nb_a;
}
