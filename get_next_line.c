/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:07:42 by abelayad          #+#    #+#             */
/*   Updated: 2023/02/15 20:24:17 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE + 1];
	char			*acc_str;
	ssize_t			read_sig;

	acc_str = ft_strjoin(buff, "");
	if (!acc_str)
		return (NULL);
	while (!ft_got_line(acc_str))
	{
		read_sig = 0;
		while (read_sig < BUFFER_SIZE + 1)
			buff[read_sig++] = 0;
		read_sig = read(fd, buff, BUFFER_SIZE);
		if (read_sig < 0 || (!ft_strlen(buff) && !ft_strlen(acc_str)))
			return (ft_free_n_return(&acc_str, NULL));
		if (!read_sig)
			return (ft_free_n_return(&acc_str, ft_strjoin(acc_str, buff)));
		acc_str = ft_free_n_return(&acc_str, ft_strjoin(acc_str, buff));
		if (!acc_str)
			return (NULL);
	}
	return (ft_get_line(acc_str, &buff));
}
