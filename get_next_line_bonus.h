/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:57:49 by abelayad          #+#    #+#             */
/*   Updated: 2022/11/10 15:29:05 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}	t_list;

int		_contains_nl(const char *str);
char	*_get_line(char *stash, int first_line);
void	*_free_and_return(void *to_free, void *to_return);
char	*_handler(char **stash_ptr, int fd);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*ft_lstadd_back(t_list **lst, int fd);
void	*_remove_node(t_list **head, int fd);

#endif