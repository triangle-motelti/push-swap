/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:06:28 by motelti           #+#    #+#             */
/*   Updated: 2025/01/30 23:55:54 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_dup(t_lst *s)
{
	int		tmp;
	t_lst	*dup;

	while (s && s->nxt)
	{
		tmp = s->value;
		dup = s;
		while (dup->nxt)
		{
			dup = dup->nxt;
			if (dup->value == tmp)
				return (-1);
		}
		s = s->nxt;
	}
	return (1);
}

void	clear_stack(t_lst **s)
{
	if (!s || !(*s))
		return ;
	clear_stack(&(*s)->nxt);
	free(*s);
	*s = NULL;
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
