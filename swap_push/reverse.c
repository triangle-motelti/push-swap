/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:13:04 by motelti           #+#    #+#             */
/*   Updated: 2025/01/25 14:34:28 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse(t_lst **s)
{
	t_lst	*tmp;

	if (!(*s) || !(*s)->nxt)
		return ;
	tmp = last(*s);
	if (tmp->prv)
		tmp->prv->nxt = NULL;
	tmp->prv = NULL;
	tmp->nxt = *s;
	(*s)->prv = tmp;
	*s = tmp;
}

void	do_rra(t_lst **stack)
{
	reverse(stack);
	ft_printf("rra\n");
}

void	do_rrb(t_lst **stack)
{
	reverse(stack);
	ft_printf("rrb\n");
}

void	do_rrr(t_lst **a_stack, t_lst **b_stack)
{
	reverse(a_stack);
	reverse(b_stack);
	ft_printf("rrr\n");
}
