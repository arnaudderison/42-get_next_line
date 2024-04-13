/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:38:19 by aderison          #+#    #+#             */
/*   Updated: 2024/04/13 13:50:03 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*ret;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		ret[i] = s1[i];
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
	if (!str)
		return (NULL);
	while (*str || (char)charac == '\0')
	{
		if (*str == (char)charac)
			return ((char *)str);
		str++;
	}
	if (*str == charac)
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (!dst || !src)
		return (0);
	i = -1;
	len = ft_strlen(src);
	if (!size)
		return (len);
	while (++i < size - 1 && src[i])
		dst[i] = src[i];
	dst[i] = 0;
	return (len);
}
