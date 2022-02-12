/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:59:22 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/12 16:03:41 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_check_error(int fd, char **line);
int		ft_backslash_checker(char *str);
char	*ft_get_line(char *str);
int		ft_return(char **buff, int i, char **line, char **str_save);
int		get_next_line(int fd, char **line);

size_t	ft_strlen_protect(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_gnljoin(char const *s1, char const *s2);
char	*ft_strdup_gnl(char *s1);
char	*ft_strchr_dup_remix(const char *s, int c);

#endif
