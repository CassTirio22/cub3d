/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:47:51 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/12 13:36:22 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*pt;

	if (!s1 || !s2)
		return (0);
	if (!(pt = (char *)ft_calloc(sizeof(char), \
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		pt[i] = s1[i];
	i -= 1;
	while (s2[++i - ft_strlen(s1)])
		pt[i] = s2[i - ft_strlen(s1)];
	return (pt);
}
