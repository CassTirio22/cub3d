/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:16:08 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/01 18:35:06 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	len = ft_strlen((char *)s);
	while (len--)
		if (s[len] == c)
			return ((char *)s + len);
	return (0);
}
