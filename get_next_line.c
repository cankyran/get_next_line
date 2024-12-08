/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:33:41 by mucankir          #+#    #+#             */
/*   Updated: 2024/12/08 05:20:05 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_unread(char *str)
{
	char	*left;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] && str)
	{
		free(str);
		return (NULL);
	}
	left = malloc(ft_strlen(str) - i + 1);
	if (!left)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i])
		left[j++] = str[i++];
	left[j] = '\0';
	free(str);
	return (left);
}

char	*ft_get_line(char *str)
{
	char	*get_line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	get_line = malloc(i + 1 + ft_strchr(str, '\n'));
	if (!get_line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		get_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		get_line[i] = str[i];
		i++;
	}
	get_line[i] = '\0';
	return (get_line);
}

char	*ft_read(char *str, int fd)
{
	int		r;
	char	*buffer;

	r = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if ((r == 0 && !str) || r == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[r] = '\0';
		if (!str && buffer)
			str = ft_strdup(buffer);
		else
			str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(str);
		return (NULL);
	}
	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	current_line = ft_get_line(str);
	str = ft_unread(str);
	return (current_line);
}
