/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:48:28 by abelayad          #+#    #+#             */
/*   Updated: 2022/11/10 15:20:05 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	total_length;

	if (!s1 || !s2)
		return (NULL);
	total_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = (char *)malloc(total_length * sizeof(char));
	if (!joined)
		return (NULL);
	while (*s1)
		*joined++ = *s1++;
	while (*s2)
		*joined++ = *s2++;
	*joined = 0;
	return (joined - (total_length - 1));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	alloc_len;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strjoin("", ""));
	alloc_len = len;
	if (len >= slen)
		alloc_len = slen;
	substr = malloc((alloc_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (len-- && s[start])
		substr[i++] = s[start++];
	substr[i] = 0;
	return (substr);
}

t_list	*ft_lstadd_back(t_list **lst, int fd)
{
	t_list	*curr_node;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> fd = fd;
	new_node -> content = NULL;
	new_node -> next = NULL;
	if (!*lst)
	{
		*lst = new_node;
		return (*lst);
	}
	curr_node = *lst;
	while (curr_node -> next)
		curr_node = curr_node -> next;
	curr_node -> next = new_node;
	return (new_node);
}

void	*_remove_node(t_list **head, int fd)
{
	t_list	*node2free;
	t_list	*tmp;

	if (!(*head))
		return (NULL);
	if ((*head)-> fd == fd)
	{
		node2free = *head;
		*head = node2free -> next;
		_free_and_return(node2free -> content, NULL);
		return (_free_and_return(node2free, NULL));
	}
	tmp = *head;
	while (tmp -> next && (tmp -> next -> fd != fd))
		tmp = tmp -> next;
	if (!(tmp -> next))
		return (NULL);
	node2free = tmp -> next;
	tmp -> next = tmp -> next -> next;
	_free_and_return(node2free -> content, NULL);
	return (_free_and_return(node2free, NULL));
}
