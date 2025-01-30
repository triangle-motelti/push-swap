/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:44:59 by motelti           #+#    #+#             */
/*   Updated: 2025/01/26 16:43:51 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strln(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strch(char *s, int c)
{
	char	s1;
	char	*s2;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	s2 = (char *) s;
	s1 = (char)c;
	while (s2[i] != s1)
	{
		if (s2[i] == '\0')
			return (NULL);
		i++;
	}
	return (s2 + i);
}

char	*ft_stjoin(char *s1, char *s2)
{
	char	*arr;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	arr = malloc(1 + ft_strlen(s1) + ft_strlen(s2) * sizeof(char));
	if (!arr)
		return (free(s1), NULL);
	ft_join(arr, s1, s2);
	free(s1);
	return (arr);
}

void	ft_join(char *dest, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
}
