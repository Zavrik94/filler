/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:42:02 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/07 18:42:03 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;
	size_t			i;
	unsigned char	flag;

	str_dest = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	i = 0;
	flag = (unsigned char)c;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		if (str_src[i] == flag)
		{
			str_dest[i] = str_src[i];
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
