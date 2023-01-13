/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:18:25 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/04 16:18:25 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;

	i = 0;
	hay = (char *) haystack;
	if (*needle == '\0')
		return ((char *)haystack);
	while (hay[i])
	{
		j = 0;
		while (hay[i + j] == needle[j] && hay[i + j] != '\0' && len > (i + j))
		{
			if (needle[j + 1] == '\0')
				return (hay + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(len - start + 1);
	if (!mem)
		return (NULL);
	while (len > start)
		mem[i++] = s[start++];
	mem[i] = '\0';
	return (mem);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1[j])
		s[i++] = s1[j++];
	while (s2[k])
		s[i++] = s2[k++];
	s[i] = '\0';
	free(s1);
	s1 = NULL;
	return (s);
}

char	*ft_strdup(char *str)
{
	char	*mem;
	int		i;

	i = 0;
	mem = malloc(ft_strlen(str) + 1);
	if (!mem)
		return (NULL);
	while (str[i])
	{
		mem[i] = str[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
