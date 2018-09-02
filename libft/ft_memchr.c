/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:30:55 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/07 18:31:04 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	ch;
	size_t			i;
	char			flag;

	s = (unsigned char *)str;
	ch = (char)c;
	i = 0;
	flag = 0;
	while (i != n)
	{
		if (s[i] == ch)
		{
			flag += 1;
			return (s + i);
		}
		else
			i++;
	}
	return (NULL);
}
