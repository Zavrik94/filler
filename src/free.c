/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:30:51 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/13 13:30:51 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	free_arr(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		ft_strdel(&arr[i]);
	free(arr);
}

void	free_num_map(int **map, int size)
{
	int		y;

	y = -1;
	while (++y < size)
		free(map[y]);
	free(map);
}

void	free_all(void)
{
	free_num_map(g_num_map, g_map.mc.y);
	free_arr(g_map.piece);
	free_arr(g_map.map);
}