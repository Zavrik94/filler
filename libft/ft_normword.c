/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:32:11 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/14 16:32:14 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_normword(char const *s)
{
	int		i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	res[i] = ft_toupper(s[i]);
	while (s[++i])
		res[i] = ft_tolower(s[i]);
	res[i] = '\0';
	return (res);
}
