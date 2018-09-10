/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 21:01:01 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/10 22:33:27 by azavrazh         ###   ########.fr       */
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

int		can_put_it(int x, int y)
{
	int		tmp_x;
	t_coo	f;
	t_coo	p;
	int		counter;

	tmp_x = x;
	if (x + g_map.pc.x > g_map.mc.x)
		return (0);
	if (y + g_map.pc.y > g_map.mc.y)
		return (0);
	f.y = y;
	p.y = 0;
	counter = 0;
	while (f.y < y + g_map.pc.y)
	{
		f.x = x;
		p.x = 0;
		while (f.x < x + g_map.pc.x)
		{
			if (g_map.map[CHEAT(f.y, g_map.mc.y)][CHEAT(f.x, g_map.mc.x)] \
					!= '.' && g_map.piece[p.y][p.x] == '*')
			{
				if (g_map.map[CHEAT(f.y, g_map.mc.y)][CHEAT(f.x, g_map.mc.x)]\
						== g_map.enmark || g_map.map[CHEAT(f.y, g_map.mc.y)]\
						[CHEAT(f.x, g_map.mc.x)] == (g_map.enmark + 32))
					return (0);
				if (counter == 0 && (g_map.map[CHEAT(f.y, g_map.mc.y)]\
							[CHEAT(f.x, g_map.mc.x)] == g_map.mymark \
							|| g_map.map[CHEAT(f.y, g_map.mc.y)]\
							[CHEAT(f.x, g_map.mc.x)] == g_map.mymark + 32))
					counter++;
				else
					return (0);
			}
			f.x++;
			p.x++;
		}
		f.y++;
		p.y++;
	}
	if (counter == 0)
		return (0);
	else
		return (1);
}

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

void	findpos(void)
{
	int		x;
	int		y;

	y = -1;
	while (g_map.map[++y])
	{
		x = -1;
		while (g_map.map[y][++x])
			if (g_map.map[y][x] == g_map.mymark || \
					g_map.map[y][x] == (g_map.mymark + 32))
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
	ft_putnbr(g_map.best.y);
	ft_putchar(' ');
	ft_putnbr(g_map.best.x);
	ft_putchar('\n');
}
