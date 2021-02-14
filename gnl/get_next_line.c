/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:19:44 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/14 14:27:36 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check_error(int fd, char **line)
{
	char	*buffer;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!(buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	return (buffer);
}

char	*ft_strdup_gnl(char *save)
{
	size_t	i;
	char	*res;

	if (!save)
		return (NULL);
	if (!(res = (char *)ft_calloc_gnl(sizeof(char), ft_strlen_gnl(save) + 1)))
		return (NULL);
	i = -1;
	while (save[++i])
		res[i] = save[i];
	return (res);
}

char	*ft_savecpy(char *save)
{
	char	*res;
	int		i;

	if (!save)
		return (NULL);
	i = -1;
	while (save[++i])
	{
		if (save[i] == '\n')
		{
			res = ft_strdup_gnl((char *)(save + i + 1));
			free((void *)save);
			return (res);
		}
	}
	free((void *)save);
	return (NULL);
}

char	*ft_linecpy(char *save)
{
	char	*res;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!(res = (char *)ft_calloc_gnl(sizeof(char), i + 1)))
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		res[i] = save[i];
		i++;
	}
	return (res);
}

int		get_next_line(int fd, char **line)
{
	char			*buffer;
	long long int	reader;
	static char		*save[OPEN_MAX];

	reader = 1;
	if (!(buffer = ft_check_error(fd, line)))
		return (-1);
	while (!ft_isreturn(save[fd]) && reader != 0)
	{
		if ((reader = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[reader] = 0;
		if (!(save[fd] = ft_strjoin(save[fd], buffer)))
			return (-1);
	}
	free(buffer);
	if (!(*line = ft_linecpy(save[fd])) ||\
	(!(save[fd] = ft_savecpy(save[fd])) && reader != 0))
		return (-1);
	if (!reader)
		return (0);
	return (1);
}
