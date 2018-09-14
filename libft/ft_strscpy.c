/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:02:49 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/13 17:02:49 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strscpy(char *str, int start)
{
	char	*res;
	int		i;

	res = (char*)malloc(sizeof(char) * (ft_strlen(str) - start) + 1);
	res[ft_strlen(str) - start] = '\0';
	i = 0;
	while (str[start])
	{
		res[i] = str[start];
		i++;
		start++;
	}
	return (res);
}
