/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:20:13 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/01 18:05:52 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*src_bis;
	unsigned char		*dst_bis;

	i = 0;
	src_bis = (const unsigned char *)src;
	dst_bis = (char unsigned *)dst;
	if (!dst && !src && len)
		return (0);
	if (src_bis <= dst_bis)
		while (++i <= len)
			dst_bis[len - i] = src_bis[len - i];
	else
		while (len--)
			*(dst_bis++) = *(src_bis++);
	return (dst);
}
