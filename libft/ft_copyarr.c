/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:35:08 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/12 20:35:08 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_copyarr(char **arr)
{
	char	**res;
	int		y;

	y = 0;
	while (arr[y])
		y++;
	res = (char**)malloc(sizeof(char*) * (y + 1));
	res[y] = NULL;
	y = -1;
	while (arr[++y])
		res[y] = ft_strdup(arr[y]);
	return (res);
}
