/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:15:06 by motelti           #+#    #+#             */
/*   Updated: 2025/01/25 14:34:02 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_lst **s_a, t_lst **s_b)
{
	t_lst	*tmp;

	if (!s_b || !*s_b)
		return ;
	tmp = (*s_b)->nxt;
	addfront(s_a, *s_b);
	*s_b = tmp;
	if (*s_b)
		(*s_b)->prv = NULL;
}

void	do_pa(t_lst **a_stack, t_lst **b_stack)
{
	push(a_stack, b_stack);
	ft_printf("pa\n");
}

void	do_pb(t_lst **a_stack, t_lst **b_stack)
{
	push(b_stack, a_stack);
	ft_printf("pb\n");
}
