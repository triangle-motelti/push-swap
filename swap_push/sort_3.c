/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:44:23 by motelti           #+#    #+#             */
/*   Updated: 2025/01/25 15:44:58 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_first_case(t_lst **s)
{
	return (((*s)->idx > (*s)->nxt->idx)
		&& ((*s)->nxt->idx < (*s)->nxt->nxt->idx)
		&& ((*s)->idx < (*s)->nxt->nxt->idx));
}

int	check_second_case(t_lst **s)
{
	return (((*s)->idx > (*s)->nxt->idx)
		&& ((*s)->nxt->idx > (*s)->nxt->nxt->idx));
}

int	check_third_case(t_lst **s)
{
	return (((*s)->idx > (*s)->nxt->idx)
		&& ((*s)->nxt->idx < (*s)->nxt->nxt->idx)
		&& ((*s)->idx > (*s)->nxt->nxt->idx));
}

int	check_fourth_case(t_lst **s)
{
	return (((*s)->idx < (*s)->nxt->idx)
		&& ((*s)->nxt->idx > (*s)->nxt->nxt->idx)
		&& ((*s)->idx < (*s)->nxt->nxt->idx));
}

int	check_fifth_case(t_lst **s)
{
	return (((*s)->idx < (*s)->nxt->idx)
		&& ((*s)->nxt->idx > (*s)->nxt->nxt->idx)
		&& ((*s)->idx > (*s)->nxt->nxt->idx));
}
