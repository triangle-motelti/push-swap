/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:37:32 by motelti           #+#    #+#             */
/*   Updated: 2025/01/25 13:41:43 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_lst **s)
{
	int	v;
	int	index;

	if (*s == NULL || (*s)->nxt == NULL)
		return ;
	v = (*s)->nxt->value;
	index = (*s)->nxt->idx;
	(*s)->nxt->value = (*s)->value;
	(*s)->nxt->idx = (*s)->idx;
	(*s)->value = v;
	(*s)->idx = index;
}

void	do_sa(t_lst **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	do_sb(t_lst **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	do_ss(t_lst **a_stack, t_lst **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	ft_printf("ss\n");
}
