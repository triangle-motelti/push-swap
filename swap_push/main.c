/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:19:06 by motelti           #+#    #+#             */
/*   Updated: 2025/01/27 18:59:39 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
