/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:19:06 by motelti           #+#    #+#             */
/*   Updated: 2025/01/30 23:55:58 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static	int	process_numbers(char **split, t_lst **a_stack)
{
	t_lst	*tmp;
	int		j;

	j = 0;
	if (!split[j])
		return (free_split(split), 0);
	while (split[j])
	{
		if (!is_valid_number(split[j]))
			return (clear_stack(a_stack), free_split(split), 0);
		if (ft_atol(split[j]) > INT_MAX || ft_atol(split[j]) < INT_MIN)
			return (clear_stack(a_stack), free_split(split), 0);
		tmp = new_lst(ft_atoi(split[j]));
		if (!tmp)
			return (clear_stack(a_stack), free_split(split), 0);
		addback(a_stack, tmp);
		j++;
	}
	return (1);
}

int	initstack(int ac, char **av, t_lst **a_stack)
{
	int		i;
	char	**split;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!process_numbers(split, a_stack))
			return (0);
		free_split(split);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_lst	*a_stack;
	t_lst	*b_stack;

	if (ac == 1)
		return (0);
	a_stack = NULL;
	b_stack = NULL;
	if (initstack(ac, av, &a_stack) == 0)
		return (ft_putstr_fd("Error\n", 2));
	else if (check_dup(a_stack) == -1)
		return (clear_stack(&a_stack),
			clear_stack(&b_stack), ft_putstr_fd("Error\n", 2));
	else
	{
		indexing(&a_stack);
		if (sorted(&a_stack) != 1)
		{
			if (size_lst(a_stack) <= 5)
				sort_3_4_5(&a_stack, &b_stack);
			else
				hossni_sorting(&a_stack, &b_stack);
		}
	}
	clear_stack(&a_stack);
	clear_stack(&b_stack);
}
