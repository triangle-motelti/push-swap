/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:20:16 by motelti           #+#    #+#             */
/*   Updated: 2025/01/27 17:49:23 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(t_lst **s)
{
	t_lst	*tmp;

	if (!s || !*s)
		return (-1);
	tmp = *s;
	while (tmp->nxt)
	{
		if (tmp->value > tmp->nxt->value)
			return (-1);
		tmp = tmp->nxt;
	}
	return (1);
}

void	reset_index(t_lst **s)
{
	t_lst	*tmp;

	tmp = *s;
	while (tmp)
	{
		tmp->idx = -1;
		tmp = tmp->nxt;
	}
	indexing(s);
}

void	rotate_min(t_lst **s, int size)
{
	int	i;

	i = 0;
	while ((*s)->idx != 0)
	{
		rotate(s);
		i++;
	}
	if ((i > (size / 2)))
	{
		if (size == 5 && i == 3)
			ft_printf("rra\n");
		ft_printf("rra\n");
	}
	else
	{
		while (i > 0)
		{
			ft_printf("ra\n");
			i--;
		}
	}
}

int	in_order(t_lst **s, int size)
{
	int	i;

	i = 0;
	while ((*s)->idx != 0)
	{
		rotate(s);
		i++;
	}
	if (sorted(s) == 1)
	{
		if (i > (size / 2))
		{
			if (size == 5 && i == 3)
				ft_printf("rra\n");
			ft_printf("rra\n");
		}
		else
			while (i-- > 0)
				ft_printf("ra\n");
		return (1);
	}
	else
		while (i-- > 0)
			reverse(s);
	return (0);
}
