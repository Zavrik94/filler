/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:32:26 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/07 18:32:29 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *mem1, const void *mem2, size_t n)
{
	size_t			i;
	size_t			res;
	unsigned char	*ch1;
	unsigned char	*ch2;

	i = 0;
	res = 0;
	ch1 = (unsigned char *)mem1;
	ch2 = (unsigned char *)mem2;
	while (i < n)
	{
		if (ch1[i] < ch2[i] || ch1[i] > ch2[i])
		{
			res = ch1[i] - ch2[i];
			return (res);
		}
		else
			i++;
	}
	return (res);
}
