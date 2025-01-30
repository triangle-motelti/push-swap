/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:57:18 by motelti           #+#    #+#             */
/*   Updated: 2025/01/25 14:34:54 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_lst **s)
{
	t_lst	*tmp;
	t_lst	*new_first;

	if (!(*s) || !(*s)->nxt)
		return ;
	tmp = last(*s);
	new_first = (*s)->nxt;
	tmp->nxt = *s;
	(*s)->prv = tmp;
	(*s)->nxt = NULL;
	new_first->prv = NULL;
	*s = new_first;
}

void	do_ra(t_lst **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	do_rb(t_lst **stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	do_rr(t_lst **a_stack, t_lst **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
	ft_printf("rr\n");
}
