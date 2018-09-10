/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 21:27:26 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/10 21:53:01 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		check_enermy_angle(void)
{
	int		x;
	int		y;
	t_coo	en;
	int		cnt;

	en.x = 0;
	en.y = 0;
	cnt = 0;
	y = -1;
	while (g_map.map[++y] && (x = -1) < 0)
		while (g_map.map[y][++x])
			if (g_map.map[y][x] == g_map.enmark \
					|| g_map.map[y][x] == g_map.enmark + 32)
			{
				en.x += x;
				en.y += y;
				cnt++;
			}
	en.x /= cnt;
	en.y /= cnt;
	if (y >= (g_map.mc.y - 1) * (en.x - (g_map.mc.x - 1)) / g_map.mc.x)
		return (0);
	else
		return (1);
}

int		check_dot_map(int **map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < g_map.mc.y)
	{
		x = -1;
		while (++x < g_map.mc.x)
			if (map[y][x] == -1)
				return (1);
	}
	return (0);
}

int		cheat_coord(int x, int mc, int status)
{
	int		angle;

	angle = check_enermy_angle();
	if (status == 0)
	{
		if (x - 1 <= 0)
			return (mc + x);
		else
			return (x - mc);
	}
	else
	{
		if (x - 1 <= 0)
			return (0);
		else
			return (mc - 1);
	}
}

int		check_around_number(int **map, int x, int y)
{
	t_coo	min;
	int		i;
	int		c;
	int		minn;
	int		ischange;

	min.y = y - 1;
	min.x = x - 1;
	minn = 10000000;
	ischange = 0;
	i = -1;
	if (map[y][x] == 0)
		return (0);
	while (++i < 3 && (c = -1) < 0)
		while (++c < 3)
			if (map[(min.y + i < 0 || min.y + i >= g_map.mc.y) ? \
					cheat_coord(min.y + i, g_map.mc.y, 1) : min.y + i]\
					[(min.x + c < 0 || min.x + c >= g_map.mc.x) ? \
					cheat_coord(min.x + c, g_map.mc.x, 0) : min.x + c]\
					< minn && map[(min.y + i < 0 || min.y + i >= \
						g_map.mc.y) ? cheat_coord(min.y + i, \
							g_map.mc.y, 1) : min.y + i][(min.x + c < 0 \
								|| min.x + c >= g_map.mc.x) ? \
					cheat_coord(min.x + c, g_map.mc.x, 0) : min.x + c] > -1)
			{
				ischange = 1;
				minn = map[(min.y + i < 0 || min.y + i >= g_map.mc.y) ? \
					cheat_coord(min.y + i, g_map.mc.y, 1) : min.y + i]\
						[(min.x + c < 0 || min.x + c >= g_map.mc.x) ? \
						cheat_coord(min.x + c, g_map.mc.x, 0) : min.x + c];
			}
	if (ischange)
		return (minn + 1);
	else
		return (-1);
}

int		**fill_around_points(int x, int y, int **map)
{
	int		i;
	int		c;

	if (x > 0 && y > 0 && x < g_map.mc.x - 1 && y < g_map.mc.y - 1)
	{
		x--;
		y--;
		i = -1;
		while (++i < 3)
		{
			c = -1;
			while (++c < 3)
				if (map[y + i][x + c] == -1)
					map[y + i][x + c] = check_around_number(map, x + c, y + i);
		}
	}
	return (map);
}

int		**fill_map_numbers(void)
{
	int		**map;
	int		i;
	int		x;
	int		y;
	int		angle;

	map = (int**)malloc(sizeof(int*) * g_map.mc.y + 1);
	map[g_map.mc.y] = NULL;
	i = -1;
	while (g_map.map[++i])
	{
		x = -1;
		map[i] = (int*)malloc(sizeof(int) * g_map.mc.x);
		while (g_map.map[i][++x])
		{
			if (g_map.map[i][x] != g_map.enmark && \
					g_map.map[i][x] != g_map.enmark + 32)
				map[i][x] = -1;
			else
				map[i][x] = 0;
		}
	}
	angle = check_enermy_angle();
	if (angle == 1)
	{
		y = g_map.mc.y;
		while (--y > -1)
		{
			x = g_map.mc.x;
			while (--x > -1)
				map[y][x] = check_around_number(map, x, y);
		}
		y = -1;
		while (++y < g_map.mc.y)
		{
			x = -1;
			while (++x < g_map.mc.x)
				map[y][x] = check_around_number(map, x, y);
		}
	}
	else
	{
		y = -1;
		while (++y < g_map.mc.y)
		{
			x = -1;
			while (++x < g_map.mc.x)
				map[y][x] = check_around_number(map, x, y);
		}
		y = g_map.mc.y;
		while (--y > -1)
		{
			x = g_map.mc.x;
			while (--x > -1)
				map[y][x] = check_around_number(map, x, y);
		}
	}
	return (map);
}
