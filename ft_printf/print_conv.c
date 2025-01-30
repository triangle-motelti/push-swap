/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:07:11 by motelti           #+#    #+#             */
/*   Updated: 2024/11/25 04:34:47 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_conv(va_list arg, const char format)
{
	int	print;

	print = 0;
	if (format == 'c')
		print += print_char(va_arg(arg, int));
	else if (format == 's')
		print += print_string(va_arg(arg, char *));
	else if (format == 'p')
		print += print_pointer(va_arg(arg, void *));
	else if (format == 'd' || format == 'i')
		print += print_int(va_arg(arg, int));
	else if (format == 'u')
		print += print_unsigned(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		print += ft_puthex(va_arg(arg, unsigned int), format);
	else
	{
		print += 1;
		write(1, &format, 1);
	}
	return (print);
}
