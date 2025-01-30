/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:06:28 by motelti           #+#    #+#             */
/*   Updated: 2025/01/27 17:36:39 by motelti          ###   ########.fr       */
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

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	initstack(int ac, char **av, t_lst **a_stack)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < ac)
	{
		j = 0;
		split = ft_split(av[i], ' ');
		if (!split[j])
			return (free_split(split), 0);
		while (split[j])
		{
			if (ft_atol(split[j]) > INT_MAX
				|| ft_atol(split[j]) < INT_MIN)
				return (free_split(split), 0);
			addback(a_stack, new_lst(ft_atoi(split[j])));
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}
