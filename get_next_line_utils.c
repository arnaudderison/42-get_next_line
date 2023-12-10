/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:38:19 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/10 21:14:36 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*ret;
	int		i;
	int		j;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[size] = 0;
	return (ret);
}

char	*ft_strchr(const char *str, int charac)
{
	while (*str)
	{
		if (*str == charac)
			return ((char *)str);
		str++;
	}
	if (*str == charac)
		return ((char *)str);
	return (NULL);
}
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = -1;
	while (++i < n)
		ptr[i] = '\0';
}
