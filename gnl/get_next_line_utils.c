/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:19:49 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/12 13:16:39 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}

void	*ft_calloc(int size, int count)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(void) * (size * count))))
		return (NULL);
	res[size * count - 1] = 0;
	return ((void *)res);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*src_bis;
	char		*dst_bis;

	dst_bis = (char *)dst;
	src_bis = (const char *)src;
	if (!dst_bis && !src_bis)
		return (NULL);
	while (n-- > 0)
		dst_bis[n] = src_bis[n];
	return ((void *)dst_bis);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	i;

	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)ft_calloc(sizeof(char), i + 1)))
	{
		if (s1)
			free((void *)s1);
		return (NULL);
	}
	ft_memcpy(res, s1, ft_strlen(s1));
	ft_memcpy(res + ft_strlen(s1), s2, ft_strlen(s2));
	free((void *)s1);
	return (res);
}

int		ft_isreturn(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}