/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:47:35 by abelayad          #+#    #+#             */
/*   Updated: 2022/11/10 15:27:02 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	_contains_nl(const char *str)
{
	while (*str++)
		if (*(str - 1) == '\n')
			return (1);
	return (0);
}

/*
types:
  1: get the first line
  0: get what is after the first line
*/
char	*_get_line(char *stash, int first_line)
{
	int		i;
	char	*ptr2free;

	i = 0;
	while (stash[i] != '\n')
		++i;
	if (first_line)
		return (ft_substr(stash, 0, i + 1));
	ptr2free = stash;
	stash = ft_substr(stash, i + 1, ft_strlen(stash) - (i + 1));
	free(ptr2free);
	return (stash);
}

void	*_free_and_return(void *to_free, void *to_return)
{
	free(to_free);
	return (to_return);
}

char	*_handler(char **stash_ptr, int fd)
{
	char	*buff;
	ssize_t	read_sig;

	if (!(*stash_ptr))
	{
		*stash_ptr = ft_strjoin("", "");
		if (!(*stash_ptr))
			return (NULL);
	}
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[BUFFER_SIZE] = 0;
	while (!_contains_nl(*stash_ptr))
	{
		read_sig = read(fd, buff, BUFFER_SIZE);
		if (read_sig <= 0)
			break ;
		while (read_sig < BUFFER_SIZE)
			buff[read_sig++] = 0;
		*stash_ptr = _free_and_return(*stash_ptr, ft_strjoin(*stash_ptr, buff));
	}
	return (_free_and_return(buff, *stash_ptr));
}
/*
in _handler(&(node -> content), fd); i pass the address of stash, so the _handler
can modify the stash
*/

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*str2ret;
	char			*joined_str;

	node = head;
	while (node && (node -> fd) != fd)
		node = node -> next;
	if (!node)
		node = ft_lstadd_back(&head, fd);
	_handler(&(node -> content), fd);
	if (!ft_strlen(node -> content))
		return (_remove_node(&head, fd));
	if (!_contains_nl(node -> content))
	{
		joined_str = ft_strjoin("", node -> content);
		free(node -> content);
		node -> content = NULL;
		return (joined_str);
	}
	str2ret = _get_line(node -> content, 1);
	node -> content = _get_line(node -> content, 0);
	return (str2ret);
}
