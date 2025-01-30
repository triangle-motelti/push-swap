/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:54:22 by motelti           #+#    #+#             */
/*   Updated: 2025/01/30 23:55:32 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int				value;
	int				idx;
	struct s_list	*prv;
	struct s_list	*nxt;
}	t_lst;

//chunks sorting
void		hossni_sorting(t_lst **a, t_lst **b);

//chunk sorting utlis
void		ataay_pushing_back_to_a(t_lst **a, t_lst **b);
int			optimize_more(t_lst **a);
void		move_max_to_top(t_lst **b);
void		find_max(t_lst *b, t_lst **max, int *max_pos, int *size);
void		handle_rotate(t_lst **a, int d, int size_chunk);
int			determine_chunk_size(int size_chunk);
void		prepare_chunk_b(t_lst **a, t_lst **b, int *i, int n);

//helper functions
t_lst		*new_lst(int content);
void		addfront(t_lst **s, t_lst *n);
void		addback(t_lst **s, t_lst *n);
t_lst		*last(t_lst *s);
int			size_lst(t_lst *s);

//swap
void		swap(t_lst **s);
void		do_sa(t_lst **stack);
void		do_sb(t_lst **stack);
void		do_ss(t_lst **a_stack, t_lst **b_stack);

//push
void		push(t_lst **s_a, t_lst **s_b);
void		do_pa(t_lst **a_stack, t_lst **b_stack);
void		do_pb(t_lst **a_stack, t_lst **b_stack);

//rotate
void		rotate(t_lst **s);
void		do_ra(t_lst **stack);
void		do_rb(t_lst **stack);
void		do_rr(t_lst **a_stack, t_lst **b_stack);

//reverse
void		reverse(t_lst **s);
void		do_rra(t_lst **stack);
void		do_rrb(t_lst **stack);
void		do_rrr(t_lst **a_stack, t_lst **b_stack);

//indexing
t_lst		*get_min(t_lst **s);
void		indexing(t_lst **s);

//hleping in sorting algo
int			sorted(t_lst **s);
void		reset_index(t_lst **s);
void		rotate_min(t_lst **s, int size);
int			in_order(t_lst **s, int size);

//sorting->3->4->5
void		sort_3(t_lst **s);
void		sort_4(t_lst **s_a, t_lst **s_b);
void		sort_3_4_5(t_lst **s_a, t_lst **s_b);

//sort 3 check
int			check_first_case(t_lst **s);
int			check_second_case(t_lst **s);
int			check_third_case(t_lst **s);
int			check_fourth_case(t_lst **s);
int			check_fifth_case(t_lst **s);

//check duplicate and free the stack
int			check_dup(t_lst *s);
void		clear_stack(t_lst **s);
int			initstack(int ac, char **av, t_lst **a_stack);
int			is_valid_number(char *str);

#endif
