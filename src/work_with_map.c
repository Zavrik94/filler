/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 21:27:26 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/17 16:30:13 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

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
	if (status == 0)
	{
		if (g_map.enmark == 'o' || g_map.enmark == 'O')
		{
			if (x - 1 <= 0)
				return (0);
			else
				return (mc - 1);
		}
		else
		{
			if (x - 1 <= 0)
				return (x + mc);
			else
				return (x - mc);
		}
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
	t_coo	i;
	int		minn;
	int		ischange;

	min.y = y - 1;
	min.x = x - 1;
	minn = 10000000;
	ischange = 0;
	i.y = -1;
	if (map[y][x] == 0)
		return (0);
	while (++i.y < 3 && (i.x = -1) < 0)
		while (++i.x < 3)
			if (if_check(map, min, minn, i) && (ischange = 1) > 0)
				minn = return_min(map, min, i);
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
	t_coo	i;

	map = init_map();
	while (check_dot_map(map))
		if ((g_map.enmark == 'X' || g_map.enmark == 'x') && (i.y = g_map.mc.y) > -1)
		{
			while (--i.y > -1 && (i.x = g_map.mc.x) > -1)
				while (--i.x > -1)
					map[i.y][i.x] = check_around_number(map, i.x, i.y);
			i.y = -1;
			while (++i.y < g_map.mc.y && (i.x = -1) < 0)
				while (++i.x < g_map.mc.x)
					map[i.y][i.x] = check_around_number(map, i.x, i.y);
		}
		else if ((i.y = -1) < 0)
		{
			while (++i.y < g_map.mc.y && (i.x = -1) > 0)
				while (++i.x < g_map.mc.x)
					map[i.y][i.x] = check_around_number(map, i.x, i.y);
			i.y = g_map.mc.y;
			while (--i.y > -1 && (i.x = g_map.mc.x) > -1)
				while (--i.x > -1)
					map[i.y][i.x] = check_around_number(map, i.x, i.y);
		}
	return (map);
}
