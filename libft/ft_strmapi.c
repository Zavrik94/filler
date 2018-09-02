/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:25:05 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/10 21:41:02 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
