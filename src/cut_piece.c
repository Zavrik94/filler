/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:52:08 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/17 23:38:45 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	search(int *minx, int *miny, int *maxx, int *maxy)
{
	t_coo	a;

	a.y = -1;
	*maxx = 0;
	*maxy = 0;
	*minx = g_map.pc.x;
	*miny = g_map.pc.y;
	while (g_map.piece[++a.y])
	{
		a.x = -1;
		while (g_map.piece[a.y][++a.x])
			if (g_map.piece[a.y][a.x] == '*')
			{
				if (a.x < *minx)
					*minx = a.x;
				if (a.y < *miny)
					*miny = a.y;
				if (a.x > *maxx)
					*maxx = a.x;
				if (a.y > *maxy)
					*maxy = a.y;
			}
	}
}

char	**for_res(t_coo min, t_coo max, t_coo len)
{
	t_coo	tmp;
	char	**res;

	tmp.y = -1;
	res = (char**)malloc(sizeof(char*) * (len.y + 1));
	res[len.y] = NULL;
	while (++tmp.y < len.y)
	{
		tmp.x = -1;
		min.x = max.x - len.x + 1;
		res[tmp.y] = (char*)malloc(sizeof(char) * (len.x + 1));
		res[tmp.y][len.x] = '\0';
		while (++tmp.x < len.x)
		{
			res[tmp.y][tmp.x] = g_map.piece[min.y][min.x];
			min.x++;
		}
		min.y++;
	}
	free(g_map.piece);
	return (res);
}

void	cut_piece(void)
{
	t_coo	min;
	t_coo	max;
	t_coo	len;
	char	**res;

	search(&min.x, &min.y, &max.x, &max.y);
	len.y = max.y - min.y + 1;
	len.x = max.x - min.x + 1;
	g_map.old_pc.x = min.x;
	g_map.old_pc.y = min.y;
	res = for_res(min, max, len);
	free(g_map.piece);
	g_map.piece = ft_copyarr(res);
	free(res);
	g_map.pc.x = len.x;
	g_map.pc.y = len.y;
}
