#include "../../incs/libft.h"

void	ft_lstaff(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%d->", tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

void	ft_lstaff_color(t_list *list, char *color)
{
	t_list *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%s%d\033[0m->", color, tmp->content);
		tmp = tmp->next;
	}
	printf("\033[31mNULL\033[0m\n");
}