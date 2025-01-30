/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:25:36 by motelti           #+#    #+#             */
/*   Updated: 2024/11/21 23:50:39 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_string(char *s);
int	print_char(char c);
int	print_int(int n);
int	print_unsigned(unsigned int uinteger);
int	print_pointer(void *pointer);
int	ft_puthex(unsigned int num, const char format);
int	print_conv(va_list vl, const char format);
int	ft_printf(const char *format, ...);

#endif
