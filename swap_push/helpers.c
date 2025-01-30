/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:57:50 by motelti           #+#    #+#             */
/*   Updated: 2025/01/25 15:30:21 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*new_lst(int content)
{
	t_lst	*s;

	s = malloc(sizeof(t_lst));
	if (!s)
		return (NULL);
	s->value = content;
	s->idx = -1;
	s->nxt = NULL;
	s->prv = NULL;
	return (s);
}

void	addfront(t_lst **s, t_lst *n)
{
	if (!s || !n)
		return ;
	if (!(*s))
	{
		*s = n;
		n->prv = NULL;
		n->nxt = NULL;
		return ;
	}
	(*s)->prv = n;
	n->nxt = *s;
	n->prv = NULL;
	*s = n;
}

void	addback(t_lst **s, t_lst *n)
{
	t_lst	*tmp;

	if (!s || !n)
		return ;
	if (!(*s))
	{
		*s = n;
		n->prv = NULL;
		n->nxt = NULL;
		return ;
	}
	tmp = last(*s);
	tmp->nxt = n;
	n->prv = tmp;
	n->nxt = NULL;
}

t_lst	*last(t_lst *s)
{
	if (!s)
		return (NULL);
	while (s->nxt)
		s = s->nxt;
	return (s);
}

int	size_lst(t_lst *s)
{
	int		i;
	t_lst	*lst;

	lst = s;
	i = 0;
	while (lst)
	{
		lst = lst->nxt;
		i++;
	}
	return (i);
}
