/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:34:29 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/10 22:55:16 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t n)
{
	size_t			i;
	int				count;
	int				k;
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char *)hay;
	d2 = (unsigned char *)need;
	count = 0;
	i = 0;
	while (d2[count])
		count++;
	while ((d1[i] && i < n) || count == 0)
	{
		k = 0;
		while ((d1[i + k] == d2[k] && i + k < n) || count == 0)
		{
			if (k == count - 1 || count == 0)
				return ((char *)hay + i);
			k++;
		}
		i++;
	}
	return (0);
}
