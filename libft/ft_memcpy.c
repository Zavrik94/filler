/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:33:48 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/07 18:33:49 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str_dest;
	unsigned char	*str_src;

	i = 0;
	str_src = (unsigned char *)str2;
	str_dest = (unsigned char *)str1;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (str_dest);
}
