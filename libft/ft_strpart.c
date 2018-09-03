/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:09:27 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/03 19:09:31 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpart(const char *str, int start, int length)
{
	char	*res;
	int		i;
	int		tmp;

	i = 0;
	tmp = start;
	res = (char*)malloc(sizeof(char) * (length + 1));
	res[length + 1] = '\0';
	while (start != (length + tmp))
	{
		res[i++] = str[start];
		start++;
	}
	return (res);
}
