/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:39:38 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/07 18:39:40 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*dst;

	i = 0;
	len = 0;
	if (!s || !f)
		return (0);
	while (s[len])
		len++;
	dst = (char*)malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = f(s[i]);
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
