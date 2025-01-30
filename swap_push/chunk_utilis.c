/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:46:25 by motelti           #+#    #+#             */
/*   Updated: 2025/01/27 15:31:59 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ataay_pushing_back_to_a(t_lst **a, t_lst **b)
{
	while ((*b))
	{
		move_max_to_top(b);
		do_pa(a, b);
	}
}

int	optimize_more(t_lst **a)
{
	t_lst	*node;
	int		d;

	node = *a;
	d = 0;
	while (node && node->nxt)
	{
		if (node->idx > node->nxt->idx)
			d--;
		d++;
		node = node->nxt;
	}
	return (d);
}

void	handle_rotate(t_lst **a, int d, int size_chunk)
{
	if (d < (size_chunk / 3))
		do_rra(a);
	else
		do_ra(a);
}

int	determine_chunk_size(int size_chunk)
{
	if (size_chunk <= 100)
		return (20);
	else
		return (33);
}

void	prepare_chunk_b(t_lst **a, t_lst **b, int *i, int n)
{
	if ((*a)->idx <= *i)
	{
		do_pb(a, b);
		(*i)++;
	}
	else if ((*a)->idx < *i + n)
	{
		do_pb(a, b);
		do_rb(b);
		(*i)++;
	}
}
