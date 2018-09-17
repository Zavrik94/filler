/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:28:54 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/17 23:10:29 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		calculate_piece(int x, int y)
{
	int		px;
	int		py;
	int		fx;
	int		fy;
	int		res;

	py = -1;
	res = 0;
	fy = y;
	while (g_map.piece[++py])
	{
		px = -1;
		fx = x;
		while (g_map.piece[py][++px])
		{
			if (g_map.piece[py][px] == '*')
				if (g_map.map[CHEAT(fy, g_map.mc.y)][CHEAT(fx, g_map.mc.x)] \
						!= g_map.mymark)
					res += g_num_map[CHEAT(fy, g_map.mc.y)]\
						[CHEAT(fx, g_map.mc.x)];
			fx++;
		}
		fy++;
	}
	return (res);
}

int		return_min(int **map, t_coo min, t_coo i)
{
	int		minn;

	minn = map[(min.y + i.y < 0 || min.y + i.y >= g_map.mc.y) ? \
					cheat_coord(min.y + i.y, g_map.mc.y, 1) : min.y + i.y]\
						[(min.x + i.x < 0 || min.x + i.x >= g_map.mc.x) ? \
						cheat_coord(min.x + i.x, g_map.mc.x, 0) : min.x + i.x];
	return (minn);
}

int		if_check(int **map, t_coo min, int minn, t_coo i)
{
	if (map[(min.y + i.y < 0 || min.y + i.y >= g_map.mc.y) ? \
		cheat_coord(min.y + i.y, g_map.mc.y, 1) : min.y + i.y]\
			[(min.x + i.x < 0 || min.x + i.x >= g_map.mc.x) ? \
				cheat_coord(min.x + i.x, g_map.mc.x, 0) : min.x + i.x]\
					< minn && map[(min.y + i.y < 0 || min.y + i.y >= \
						g_map.mc.y) ? cheat_coord(min.y + i.y, \
							g_map.mc.y, 1) : min.y + i.y][(min.x + i.x < 0 \
								|| min.x + i.x >= g_map.mc.x) ? \
					cheat_coord(min.x + i.x, g_map.mc.x, 0) : min.x + i.x] > -1)
		return (1);
	else
		return (0);
}

int		**init_map(void)
{
	t_coo	i;
	int		**map;

	map = (int**)malloc(sizeof(int*) * (g_map.mc.y + 1));
	map[g_map.mc.y] = NULL;
	i.y = -1;
	while (g_map.map[++i.y])
	{
		i.x = -1;
		map[i.y] = (int*)malloc(sizeof(int) * (g_map.mc.x + 1));
		while (g_map.map[i.y][++i.x])
		{
			if (g_map.map[i.y][i.x] != g_map.enmark && \
					g_map.map[i.y][i.x] != g_map.enmark + 32)
				map[i.y][i.x] = -1;
			else
				map[i.y][i.x] = 0;
		}
	}
	return (map);
}
