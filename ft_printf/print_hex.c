/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:55:32 by motelti           #+#    #+#             */
/*   Updated: 2024/11/25 18:39:23 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static	int	ft_put_hex(unsigned int num, const char format)
{
	char	*lower_hex;
	char	*upper_hex;
	int		count;

	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
	{
		count += ft_put_hex(num / 16, format);
		count += ft_put_hex(num % 16, format);
	}
	else
	{
		if (format == 'x')
			ft_putchar(lower_hex[num]);
		if (format == 'X')
			ft_putchar(upper_hex[num]);
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned int num, const char format)
{
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	return (ft_put_hex(num, format));
}
