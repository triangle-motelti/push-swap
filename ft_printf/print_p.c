/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:21:07 by motelti           #+#    #+#             */
/*   Updated: 2024/11/21 23:13:01 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_pointerhex(size_t hex, int *p_count)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (hex < 16)
		*p_count += write(1, tab + hex, 1);
	else
	{
		print_pointerhex(hex / 16, p_count);
		*p_count += write(1, tab + (hex % 16), 1);
	}
}

int	print_pointer(void *pointer)
{
	int				count;

	count = write(1, "0x", 2);
	print_pointerhex((size_t)pointer, &count);
	return (count);
}
