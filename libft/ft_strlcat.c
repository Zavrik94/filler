/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:11:35 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/14 15:44:37 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	a;
	size_t	b;
	size_t	n;

	n = dstsize;
	dstlen = 0;
	while (dst[dstlen] && n-- != 0)
		dstlen++;
	n = dstsize - dstlen;
	a = dstlen;
	b = 0;
	if (n-- == 0)
		return (dstlen + ft_strlen((char *)src));
	while (src[b])
	{
		if (n != 0)
		{
			*(dst + a++) = src[b];
			n--;
		}
		b++;
	}
	*(dst + a) = '\0';
	return (dstlen + b);
}
