/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:22:19 by motelti           #+#    #+#             */
/*   Updated: 2025/01/25 15:29:26 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	hossni_sorting(t_lst **a, t_lst **b)
{
	int	i;
	int	n;
	int	size_chunck;
	int	d;

	i = 0;
	d = optimize_more(a);
	size_chunck = size_lst(*a);
	n = determine_chunk_size(size_chunck);
	while ((*a) != NULL)
	{
		prepare_chunk_b(a, b, &i, n);
		if ((*a) != NULL && (*a)->idx >= i + n)
			handle_rotate(a, d, size_chunck);
	}
	while (*b != NULL)
		ataay_pushing_back_to_a(a, b);
}

void	move_max_to_top(t_lst **b)
{
	t_lst	*max;
	int		max_pos;
	int		size;
	int		from_up;
	int		from_down;

	find_max(*b, &max, &max_pos, &size);
	if (max_pos == -1)
		return ;
	from_up = max_pos;
	from_down = size - from_up - 1;
	while (*b && max->prv != NULL)
	{
		if (from_up <= from_down)
			do_rb(b);
		else
			do_rrb(b);
	}
}

void	find_max(t_lst *b, t_lst **max, int *max_pos, int *size)
{
	t_lst	*index;
	int		max_idx;

	max_idx = -1;
	index = b;
	*max = index;
	*max_pos = -1;
	*size = 0;
	while (index != NULL)
	{
		(*size)++;
		if (index->idx > max_idx)
		{
			*max = index;
			max_idx = index->idx;
			*max_pos = *size - 1;
		}
		index = index->nxt;
	}
}
