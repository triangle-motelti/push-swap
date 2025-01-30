/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:44:27 by motelti           #+#    #+#             */
/*   Updated: 2025/01/28 11:50:16 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*first_line(char *start)
{
	int		i;
	char	*line;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\n')
		i++;
	line = (char *)malloc(1 + i * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*next_line(char *start)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i += (start[i] == '\n');
	new_buff = (char *)malloc(ft_strln(start) - i + 1);
	if (!new_buff)
		return (free(start), NULL);
	j = 0;
	while (start[i + j])
	{
		new_buff[j] = start[i + j];
		j++;
	}
	new_buff[j] = '\0';
	free(start);
	return (new_buff);
}

char	*read_line(int fd, char *start_str)
{
	char	*tmp;
	int		fd_read;

	tmp = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!tmp)
		return (NULL);
	fd_read = 1;
	while (!(ft_strch(start_str, '\n')) && fd_read > 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(tmp);
			free(start_str);
			return (NULL);
		}
		tmp[fd_read] = '\0';
		start_str = ft_stjoin(start_str, tmp);
		if (!start_str)
			return (free(tmp), free(start_str), NULL);
	}
	free(tmp);
	return (start_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = read_line(fd, str);
	if (!str)
	{
		str = NULL;
		return (NULL);
	}
	line = first_line(str);
	if (!line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = next_line(str);
	return (line);
}
