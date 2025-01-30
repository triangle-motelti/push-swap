/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:25:14 by motelti           #+#    #+#             */
/*   Updated: 2024/11/25 03:14:24 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg;
	int		char_printed;

	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	char_printed = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_printed += print_conv(arg, format[i + 1]);
			i++;
		}
		else
		{
			if (format[i] != '\0')
				char_printed += print_char(format[i]);
		}
		if (format[i] != '\0')
			i++;
	}
	return (va_end(arg), char_printed);
}
