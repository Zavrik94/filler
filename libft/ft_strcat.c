/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:36:45 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/07 18:36:46 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;
	size_t			k;

	k = 0;
	i = ft_strlen(s1);
	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (s[k])
	{
		d[i + k] = s[k];
		k++;
	}
	d[i + k] = '\0';
	return ((char *)d);
}
