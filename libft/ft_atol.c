/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:59:47 by motelti           #+#    #+#             */
/*   Updated: 2025/01/30 20:26:15 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == 32)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	return (0);
}

long	ft_atol(const char *p)
{
	int		i;
	int		s;
	long	r;

	i = 0;
	s = 1;
	r = 0;
	while (ft_isspace(p[i]))
		i++;
	if (p[i] == '-')
		s *= -1;
	i += (p[i] == '+' || p[i] == '-');
	if (ft_isdigit(p[i]) == 0)
		return (LONG_MAX);
	while (ft_isdigit(p[i]))
	{
		r = (r * 10) + (p[i] - '0');
		i++;
	}
	if (p[i] && ft_isascii(p[i]))
		return (LONG_MAX);
	r *= s;
	return (r);
}
