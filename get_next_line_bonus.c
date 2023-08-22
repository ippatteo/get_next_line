/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:45:28 by mcamilli          #+#    #+#             */
/*   Updated: 2023/05/25 08:57:20 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

char	*risultato(char *s)
{
	int		i;
	char	*knife;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	knife = (char *)malloc((i + 2) * sizeof(char));
	if (!knife)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		knife[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		knife[i] = s[i];
		i++;
	}
	knife[i] = '\0';
	return (knife);
}

char	*ft_read_file(int fd, char *stash)
{
	char	*buffer;
	int		ret_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ret_read = 1;
	while (!ft_strchr(stash, '\n') && ret_read != 0)
	{
		ret_read = (int)read(fd, buffer, BUFFER_SIZE);
		if (ret_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[ret_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*next(char *s)
{
	int		i;
	char	*knife;
	int		t;

	i = 0;
	t = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	i++;
	knife = (char *)malloc((ft_strlen(s) - i + 1) * sizeof(char));
	if (!knife)
		return (NULL);
	while (s[i] != '\0')
		knife[t++] = s[i++];
	knife[t] = '\0';
	free(s);
	return (knife);
}

char	*get_next_line(int fd)
{
	static char	*fox[4096];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fox[fd] = ft_read_file(fd, fox[fd]);
	if (!fox[fd])
		return (NULL);
	result = risultato(fox[fd]);
	fox[fd] = next(fox[fd]);
	return (result);
}
