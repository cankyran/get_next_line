/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 01:31:26 by mucankir          #+#    #+#             */
/*   Updated: 2024/12/08 05:17:11 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, int a)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (char)a)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *str, char *buffer)
{
	int		i;
	int		j;
	char	*joined;

	if (!str && !buffer)
		return (NULL);
	joined = malloc(ft_strlen(str) + ft_strlen(buffer) + 1);
	if (!joined)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		joined[i] = str[i];
	j = 0;
	while (buffer[j])
		joined[i++] = buffer[j++];
	free(str);
	joined[i] = '\0';
	return (joined);
}
