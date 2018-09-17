/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 21:01:01 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/17 10:20:45 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	check_around_point(int x, int y)
{
	int		xmin;
	int		ymin;
	int		xmax;
	int		ymax;

	ymin = y - g_map.pc.y;
	xmin = x - g_map.pc.x + 1;
	ymax = y;
	xmax = x;
	while (++ymin <= ymax)
	{
		xmin = x - g_map.pc.x;
		while (++xmin <= xmax)
			if (can_put_it(xmin, ymin) == 1)
			{
				if (calculate_piece(xmin, ymin) < g_map.bestsum)
				{
					g_map.bestsum = calculate_piece(xmin, ymin);
					g_map.best.x = xmin;
					g_map.best.y = ymin;
				}
			}
	}
}

int		check_around_dots(int x, int y)
{
	t_coo	min;
	int		i;
	int		c;

	min.y = y - 1;
	min.x = x - 1;
	i = -1;
	while (++i < 3 && (c = -1) < 0)
		while (++c < 3)
			if (g_map.map[(min.y + i < 0 || min.y + i >= g_map.mc.y) ? \
					cheat_coord(min.y + i, g_map.mc.y, 1) : min.y + i]\
					[(min.x + c < 0 || min.x + c >= g_map.mc.x) ? \
					cheat_coord(min.x + c, g_map.mc.x, 0) : min.x + c] == '.')
				return (1);
	return (0);
}

void	findpos(void)
{
	int		x;
	int		y;

	y = -1;
	while (g_map.map[++y])
	{
		x = -1;
		while (g_map.map[y][++x])
			if ((g_map.map[y][x] == g_map.mymark || \
					g_map.map[y][x] == (g_map.mymark + 32)) &&\
					check_around_dots(x, y))
				check_around_point(x, y);
	}
}

int		sum_all_map(void)
{
	int		x;
	int		y;
	int		res;

	y = -1;
	res = 0;
	while (g_map.map[++y])
	{
		x = -1;
		while (g_map.map[y][++x])
			res += g_num_map[y][x];
	}
	return (res);
}

void	filler_algo(void)
{
	g_num_map = fill_map_numbers();
	g_map.bestsum = sum_all_map();
	findpos();
	free_all();
	ft_putnbr(g_map.best.y - g_map.old_pc.y);
	ft_putchar(' ');
	ft_putnbr(g_map.best.x - g_map.old_pc.x);
	ft_putchar('\n');
}
