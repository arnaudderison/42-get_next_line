/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:59:42 by arnaud            #+#    #+#             */
/*   Updated: 2024/04/10 17:00:50 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join_free(char **s1, char *s2)
{
	char	*ret;

	if (*s1)
		ret = ft_strjoin(*s1, s2);
	else
		ret = ft_strjoin("", s2);
	free(*s1);
	return (ret);
}

static char	*get_buffer_file(int fd, char **buffer, char **tmp_buffer)
{
	int	bytes;

	while (!(*tmp_buffer) || !ft_strchr(*buffer, '\n'))
	{
		bytes = read(fd, *tmp_buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(*tmp_buffer);
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		if (bytes == 0)
			break ;
		(*tmp_buffer)[bytes] = '\0';
		*buffer = ft_join_free(buffer, *tmp_buffer);
		if (!(*buffer))
		{
			free(*tmp_buffer);
			return (NULL);
		}
	}
	free(*tmp_buffer);
	return (*buffer);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		len;

	if (!buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, (size_t)(len + 1));
	return (line);
}

char	*clean_buffer(char *line, char **buffer)
{
	int		start;
	int		end;
	char	*new_buffer;

	if (!line || !buffer)
		return (NULL);
	start = ft_strlen(line);
	end = ft_strlen(*buffer);
	if (end - start < 0 || end - start == 0)
	{
		free(*buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(end - start + 1);
	if (!new_buffer)
	{
		free(*buffer);
		return (NULL);
	}
	ft_strlcpy(new_buffer, *buffer + start, end - start + 1);
	free(*buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT32_MAX)
		return (NULL);
	tmp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp_buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = get_buffer_file(fd, &buffer, &tmp_buffer);
	line = get_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = clean_buffer(line, &buffer);
	return (line);
}
