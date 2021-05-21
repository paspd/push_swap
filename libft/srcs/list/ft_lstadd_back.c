/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:20:53 by ldauga            #+#    #+#             */
/*   Updated: 2021/05/21 11:21:51 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	ft_lstadd_back(t_list **list, int valeur)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof(*new));
	if (new == NULL)
		exit(EXIT_FAILURE);
	if (*list == NULL)
	{
		new->content = valeur;
		new->next = NULL;
		*list = new;
		return ;
	}
	else
	{
		new->content = valeur;
		new->next = NULL;
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
