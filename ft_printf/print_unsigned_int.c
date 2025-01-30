/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:58:04 by motelti           #+#    #+#             */
/*   Updated: 2024/11/21 23:43:48 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_u_int(unsigned int u_int, int *p_count)
{
	char	*digit;

	digit = "0123456789";
	if (u_int < 10)
		*p_count += write(1, digit + u_int, 1);
	else
	{
		print_u_int(u_int / 10, p_count);
		*p_count += write(1, digit + (u_int % 10), 1);
	}
}

int	print_unsigned(unsigned int uinteger)
{
	int				count;

	count = 0;
	print_u_int(uinteger, &count);
	return (count);
}
