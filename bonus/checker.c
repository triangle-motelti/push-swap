/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:51:58 by motelti           #+#    #+#             */
/*   Updated: 2025/01/28 11:44:50 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"

static	int	initialize_stacks(int ac, char **av, t_lst **a_stack)
{
	if (ac == 1)
		return (0);
	*a_stack = NULL;
	if (initstack(ac, av, a_stack) == 0)
		return (ft_putstr_fd("Error\n", 2));
	if (check_dup(*a_stack) == -1)
		return (ft_putstr_fd("Error\n", 2));
	return (1);
}

static	void	process_instructions(t_lst **a_stack, t_lst **b_stack)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		if (*instruction != '\0')
		{
			if (!instruction_part1(instruction, a_stack, b_stack))
			{
				clear_stack(a_stack);
				clear_stack(b_stack);
				ft_putstr_fd("Error\n", 2);
				free(instruction);
				exit(1);
			}
		}
		if (instruction)
		{
			free(instruction);
			instruction = NULL;
		}
		instruction = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_lst	*a_stack;
	t_lst	*b_stack;

	if (!initialize_stacks(ac, av, &a_stack))
		return (0);
	b_stack = NULL;
	process_instructions(&a_stack, &b_stack);
	if (sorted(&a_stack) == 1 && b_stack == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clear_stack(&a_stack);
	clear_stack(&b_stack);
	return (0);
}

int	instruction_part2(char *instruction, t_lst **a_stack, t_lst **b_stack)
{
	if (ft_strncmp(instruction, "ra\n", 3) == 0)
		rotate(a_stack);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rotate(b_stack);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
	{
		rotate(a_stack);
		rotate(b_stack);
	}
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		reverse(a_stack);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		reverse(b_stack);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
	{
		reverse(a_stack);
		reverse(b_stack);
	}
	else
		return (0);
	return (1);
}

int	instruction_part1(char *instruction, t_lst **a_stack, t_lst **b_stack)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		swap(a_stack);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		swap(b_stack);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
	{
		swap(a_stack);
		swap(b_stack);
	}
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		push(a_stack, b_stack);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		push(b_stack, a_stack);
	else
		return (instruction_part2(instruction, a_stack, b_stack));
	return (1);
}
