/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:12:58 by mpihur            #+#    #+#             */
/*   Updated: 2023/11/20 19:31:54 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

short	ft_strchr_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen_gnl(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*joiner(char *str1, char *str2, int len, char *res)
{
	int	i;
	int	j;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		res[i] = str2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	free(str1);
	free(str2);
	return (res);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	size_t	len;

	if (!s2)
		return (NULL);
	res = NULL;
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	res = joiner(s1, s2, len, res);
	return (res);
}
