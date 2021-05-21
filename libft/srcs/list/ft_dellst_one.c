/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellst_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:16:21 by ldauga            #+#    #+#             */
/*   Updated: 2021/05/21 11:20:22 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	ft_dellst_one(t_list **list, int i)
{
	t_list	*tmp;
	t_list	*ptmp;
	int		limit;

	limit = 1;
	if (*list == NULL)
		return ;
	if ((*list)->next == NULL)
	{
		free(*list);
		*list = NULL;
		return ;
	}
	tmp = *list;
	ptmp = *list;
	while (limit++ != i && tmp->next != NULL)
	{
		ptmp = tmp;
		tmp = tmp->next;
	}
	ptmp->next = tmp->next;
	if (tmp->next == NULL)
		ptmp->next = NULL;
	free(tmp);
}
