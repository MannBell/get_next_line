/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:07:47 by abelayad          #+#    #+#             */
/*   Updated: 2023/02/15 20:24:27 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	total_length;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	total_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc(total_length * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = 0;
	return (joined);
}

char	*ft_free_n_return(char	**ptr, char *to_ret)
{
	free(*ptr);
	*ptr = NULL;
	return (to_ret);
}

int	ft_got_line(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_line(char *acc_str, char (*buff)[BUFFER_SIZE + 1])
{
	size_t	i;
	size_t	j;
	char	*line;

	if (!acc_str)
		return (NULL);
	i = 0;
	while (acc_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1 + 1));
	if (!line)
		return (free(acc_str), NULL);
	j = 0;
	while (j < i + 1)
	{
		line[j] = acc_str[j];
		j++;
	}
	line[j] = 0;
	j = 0;
	while (acc_str[i++])
		(*buff)[j++] = acc_str[i];
	while (j < BUFFER_SIZE + 1)
		(*buff)[j++] = 0;
	return (free(acc_str), line);
}
