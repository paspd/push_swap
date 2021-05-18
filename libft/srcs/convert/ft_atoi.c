/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:49:08 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:16:18 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	ft_isdigit2(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	negative;
	int	i;
	int	result;

	i = 0;
	result = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		negative = negative * -1;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit2(str[i]))
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * negative);
}
