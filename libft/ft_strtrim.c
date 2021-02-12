/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:14:06 by ctirions          #+#    #+#             */
/*   Updated: 2020/11/20 15:04:06 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*dst;
	size_t	s_size;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s_size = ft_strlen(s1);
	while (s_size && ft_strchr(set, s1[s_size]))
		s_size--;
	dst = ft_substr((char *)s1, 0, s_size + 1);
	return (dst);
}
