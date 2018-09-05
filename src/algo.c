#include <filler.h>

int		calculate_piece(int	x, int y)
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
				if (g_map.map[CHEAT(fy, g_map.mc.y)][CHEAT(fx, g_map.mc.x)] != g_map.mymark)
					res += g_num_map[CHEAT(fy, g_map.mc.y)][CHEAT(fx, g_map.mc.x)];
			fx++;
		}
		fy++;
	}
	return (res);
}

int		can_put_it(int	x, int	y)
{
	int		tmp_x;
	int		fx;
	int		fy;
	int		px;
	int		py;
	int		counter;
	tmp_x = x;

	// if (x + g_map.pc.x - 1 > g_map.mc.x)
	// 	return (0);
	// if (y + g_map.pc.y - 1 > g_map.mc.y)
	// 	return (0);
	fy = y;
	py = 0;
	counter = 0;
	while (fy < y + g_map.pc.y)
	{
		fx = x;
		px = 0;
		while (fx < x + g_map.pc.x)
		{
			// printf("xmap = %d ymap = %d xpiece = %d piece = %d map = %c piece = %c\n",fx, fy, px, py, g_map.map[fy][fx], g_map.piece[py][px]);
			// if (g_map.map[fy < 0 ? fy + g_map.mc.y : fy][fx < 0 ? fx + g_map.mc.x : fx] != '.' && g_map.piece[py][px] == '*')
			// {
			// 	if (counter == 0 && g_map.map[fy < 0 ? fy + g_map.mc.y : fy][fx < 0 ? fx + g_map.mc.x : fx] == g_map.mymark)
			// 		counter++;
			// 	else
			// 		return (0);
			// }
			if (g_map.map[CHEAT(fy, g_map.mc.y)][CHEAT(fx, g_map.mc.x)] != '.' && g_map.piece[py][px] == '*')
			{
				if (g_map.map[CHEAT(fy, g_map.mc.y)][CHEAT(fx, g_map.mc.x)] == g_map.enmark || g_map.map[CHEAT(fy, g_map.mc.y)][CHEAT(fx, g_map.mc.x)] == (g_map.enmark + 32))
					return (0);
				// printf("%c\n",g_map.map[CHEAT(fy, g_map.mc.y)][CHEAT(fx, g_map.mc.x)]);
				if (counter == 0 && (g_map.map[CHEAT(fy, g_map.mc.y)][CHEAT(fx, g_map.mc.x)] == g_map.mymark || g_map.map[CHEAT(fy, g_map.mc.y)][CHEAT(fx, g_map.mc.x)] == g_map.mymark + 32))
					counter++;
				else
					return (0);
			}
			fx++;
			px++;
		}
		fy++;
		py++;
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

	ymin = y - g_map.pc.y + 1;//(y - g_map.pc.y + 1 > 0) ? y - g_map.pc.y + 1 : 0;
	xmin = x - g_map.pc.x + 1;//(x - g_map.pc.x + 1 > 0) ? x - g_map.pc.x + 1 : 0;
	ymax = y;//y + g_map.pc.y - 1 > g_map.mc.y ? g_map.mc.y : y + g_map.pc.y - 1;
	xmax = x;//x + g_map.pc.x - 1 > g_map.mc.x ? g_map.mc.x : x + g_map.pc.x - 1;
	//printf("ymin = %d xmin = %d ymax = %d xmax = %d\n", ymin, xmin, ymax, xmax);
	while (ymin <= ymax)
	{
		xmin = x - g_map.pc.x + 1;//x - g_map.pc.x + 1 > 0 ? x - g_map.pc.x + 1 : 0;
		while (xmin <= xmax)
		{
			//printf("x = %d y = %d\n", xmin, ymin);
			if (can_put_it(xmin, ymin) == 1) 
			{
				// printf("x = %d, y = %d calc = %d\n", xmin, ymin, calculate_piece(xmin, ymin));
				if (calculate_piece(xmin, ymin) < g_map.bestsum)
				{
					g_map.bestsum = calculate_piece(xmin, ymin);
					g_map.best.x = xmin;
					g_map.best.y = ymin;
				}
			}
				//printf("x = %d y = %d\n", xmin, ymin);
			xmin++;	
		}
		ymin++;
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
			if (g_map.map[y][x] == g_map.mymark)
				check_around_point(x, y);
				// if (can_put_it(x, y) == 1)
				// {
				// 	g_points[g_cnt_points].x = x;
				// 	g_points[g_cnt_points++].y = y;
				// }
	}
}

int		sum_all_map()
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
	//'X' = 'x' - 32;
	//'O' = 'o' - 32;
	g_num_map = fill_map_numbers();
	g_map.bestsum = sum_all_map();
	// ft_printnumbarr(g_num_map, g_map.mc.x, g_map.mc.y);
	findpos();
	// printf("%d %d\n", g_map.best.y, g_map.best.x);
	// fflush(stdout);
	ft_putnbr(g_map.best.y);
	ft_putchar(' ');
	ft_putnbr(g_map.best.x);
	ft_putchar('\n');
}