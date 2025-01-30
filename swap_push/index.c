/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:21:35 by motelti           #+#    #+#             */
/*   Updated: 2025/01/24 17:26:11 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*get_min(t_lst **s)
{
	int		min;
	t_lst	*lst;
	t_lst	*min_lst;

	min = 0;
	lst = *s;
	min_lst = NULL;
	if (!(*s))
		return (NULL);
	while (lst)
	{
		if ((lst->idx == -1) && (!(min) || (lst->value < min_lst->value)))
		{
			min_lst = lst;
			min = 1;
		}
		lst = lst->nxt;
	}
	return (min_lst);
}

void	indexing(t_lst **s)
{
	t_lst	*lst;
	int		i;

	if (s == NULL)
		return ;
	lst = get_min(s);
	i = 0;
	while (lst)
	{
		lst->idx = i++;
		lst = get_min(s);
	}
}
