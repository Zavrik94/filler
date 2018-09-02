/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:29:55 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/14 19:30:08 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *s)
{
	char	*res;
	int		i;
	int		c;

	i = 0;
	if (!s)
		return (NULL);
	c = ft_strlen(s);
	if (!(res = (char*)malloc(c + 1)))
		return (NULL);
	while (--c != -1)
	{
		res[i] = s[c];
		i++;
	}
	res[i] = '\0';
	return (res);
}
