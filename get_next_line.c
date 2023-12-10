/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:59:42 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/10 21:11:58 by arnaud           ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = get_buffer_file(fd, buffer);

	printf("buffer: |%s|", buffer);
}