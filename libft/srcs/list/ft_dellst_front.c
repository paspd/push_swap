/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellst_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:16:13 by ldauga            #+#    #+#             */
/*   Updated: 2021/05/21 11:21:53 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	ft_dellst_front(t_list **list)
{
	t_list	*tmp;

	if (list == NULL)
		return ;
	tmp = (*list)->next;
	free(*list);
	*list = tmp;
}
