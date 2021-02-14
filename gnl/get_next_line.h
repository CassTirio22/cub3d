/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:50:21 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/14 14:25:33 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

/*
**		MAIN FONCLTIONS
*/

char	*ft_check_error(int fd, char **line);
int		get_next_line(int fd, char **line);
char	*ft_linecpy(char *save);
char	*ft_savecpy(char *save);
char	*ft_strdup_gnl(char *save);

/*
**		UTILS FONCLTIONS
*/

int		ft_strlen_gnl(const char *str);
void	*ft_calloc_gnl(int size, int count);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_isreturn(char *str);

#endif