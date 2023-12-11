/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:59:42 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/11 09:04:39 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_free(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	free(s1);
	return (ret);
}

char	*get_buffer_file(int fd, char *buffer)
{
	char	*tmp_buffer;
	int		bytes;

	if (!buffer)
		buffer = malloc(1);
	tmp_buffer = malloc(BUFFER_SIZE + 1);
	if (!tmp_buffer)
		return (NULL);
	while (!ft_strchr(tmp_buffer, '\n'))
	{
		bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(tmp_buffer);
			return (NULL);
		}
		tmp_buffer[bytes] = 0;
		buffer = ft_join_free(buffer, tmp_buffer);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}
char	*get_line(char *buffer)
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
	ft_strlcpy(line, buffer, len + 1);
	return (line);
}
char	*clean_buffer(char *line, char *buffer)
{
	int		start;
	int		end;
	int		size;
	char	*new_buffer;

	if (!line || !buffer)
		return (NULL);
	start = ft_strlen(line);
	end = ft_strlen(buffer);
	size = end - start;
	if (size < 0)
		return (NULL);
	new_buffer = (char *)malloc(size + 1);
	if (!new_buffer)
		return (NULL);
	ft_strlcpy(new_buffer, buffer + start, size + 1);
	free(buffer);
	return (new_buffer);
}
char	*get_next_line(int fd)
{
	static char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = get_buffer_file(fd, buffer);
	line = get_line(buffer);
	buffer = clean_buffer(line, buffer);
	return (line);
}