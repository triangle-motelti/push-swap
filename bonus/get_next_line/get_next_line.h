/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:46:13 by motelti           #+#    #+#             */
/*   Updated: 2025/01/27 19:01:57 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE INT_MAX
# endif

# include "../../libft/libft.h"
# include "../../push_swap.h"

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strln(char *s);
char	*ft_strch(char *s, int c);
char	*ft_stjoin(char *s1, char *s2);
void	ft_join(char *dest, char *s1, char *s2);

char	*get_next_line(int fd);
char	*first_line(char *start);
char	*next_line(char *start);

int		instruction_part1(char *instruction, t_lst **a_stack, t_lst **b_stack);

#endif