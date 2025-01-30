/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorte_3_4_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:34:59 by motelti           #+#    #+#             */
/*   Updated: 2025/01/25 15:47:49 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_lst **s)
{
	if (!s || !*s || !(*s)->nxt || !(*s)->nxt->nxt)
		return ;
	while (sorted(s) != 1)
	{
		if (check_first_case(s))
			do_sa(s);
		else if (check_second_case(s))
		{
			do_sa(s);
			do_rra(s);
		}
		else if (check_third_case(s))
			do_ra(s);
		else if (check_fourth_case(s))
		{
			do_sa(s);
			do_ra(s);
		}
		else if (check_fifth_case(s))
			do_rra(s);
	}
}

void	sort_4(t_lst **s_a, t_lst **s_b)
{
	if (in_order(s_a, 4) == 1)
		return ;
	rotate_min(s_a, 4);
	do_pb(s_a, s_b);
	sort_3(s_a);
	do_pa(s_a, s_b);
}

void	sort_3_4_5(t_lst **s_a, t_lst **s_b)
{
	int	size;

	size = size_lst(*s_a);
	if (size == 3)
		sort_3(s_a);
	else if (size == 4)
		sort_4(s_a, s_b);
	else
	{
		if (in_order(s_a, 5) == 1)
			return ;
		rotate_min(s_a, 5);
		do_pb(s_a, s_b);
		reset_index(s_a);
		sort_4(s_a, s_b);
		do_pa(s_a, s_b);
	}
}
