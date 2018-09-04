#include <filler.h>

void	print_points(void)
{
	int	i;

	i = -1;
	while (++i < g_cnt_points)
		printf("point %d x = %d y = %d\n", i, g_points[i].x, g_points[i].y);
}

int		check_exist_coords(int	x, int	y)
{
	int		i;

	i = -1;
	while (++i < g_cnt_points)
			if (g_points[i].x == x && g_points[i].y == y)
				return (1);
	return (0);
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

	if (x + g_map.pc.x - 1 > g_map.mc.x)
		return (0);
	if (y + g_map.pc.y - 1 > g_map.mc.y)
		return (0);
	fy = y;
	py = 0;
	counter = 0;
	while (fy < y + g_map.pc.y)
	{
		fx = x;
		px = 0;
		while (fx < x + g_map.pc.x)
		{
			//printf("xmap = %d ymap = %d xpiece = %d piece = %d map = %c piece = %c\n",fx, fy, px, py, g_map.map[fy][fx], g_map.piece[py][px]);
			if (g_map.map[fy][fx] != '.' && g_map.piece[py][px] == '*')
			{
				if (counter == 0 && g_map.map[fy][fx] == g_mymark)
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

void	count_all_point(int x, int y)
{
	int		xmin;
	int		ymin;
	int		xmax;
	int		ymax;

	ymin = y - g_map.pc.y + 1 > 0 ? y - g_map.pc.y + 1 : 0;
	xmin = x - g_map.pc.x + 1 > 0 ? x - g_map.pc.x + 1 : 0;
	ymax = y;//y + g_map.pc.y - 1 > g_map.mc.y ? g_map.mc.y : y + g_map.pc.y - 1;
	xmax = x;//x + g_map.pc.x - 1 > g_map.mc.x ? g_map.mc.x : x + g_map.pc.x - 1;
	//printf("ymin = %d xmin = %d ymax = %d xmax = %d\n", ymin, xmin, ymax, xmax);
	while (ymin <= ymax)
	{
		xmin = x - g_map.pc.x + 1 > 0 ? x - g_map.pc.x + 1 : 0;
		while (xmin <= xmax)
		{
			if (can_put_it(xmin, ymin) == 1)
				g_cnt_points++;
			xmin++;	
		}
		ymin++;
	}
}

void	check_around_point(int x, int y)
{
	int		xmin;
	int		ymin;
	int		xmax;
	int		ymax;

	ymin = y - g_map.pc.y + 1 > 0 ? y - g_map.pc.y + 1 : 0;
	xmin = x - g_map.pc.x + 1 > 0 ? x - g_map.pc.x + 1 : 0;
	ymax = y;//y + g_map.pc.y - 1 > g_map.mc.y ? g_map.mc.y : y + g_map.pc.y - 1;
	xmax = x;//x + g_map.pc.x - 1 > g_map.mc.x ? g_map.mc.x : x + g_map.pc.x - 1;
	//printf("ymin = %d xmin = %d ymax = %d xmax = %d\n", ymin, xmin, ymax, xmax);
	while (ymin <= ymax)
	{
		xmin = x - g_map.pc.x + 1 > 0 ? x - g_map.pc.x + 1 : 0;
		while (xmin <= xmax)
		{
			if (can_put_it(xmin, ymin) == 1)
				if (check_exist_coords(x, y) == 0)
				{
					g_points[g_cnt_points].x = x;
					g_points[g_cnt_points++].y = y;
				}
			xmin++;	
		}
		ymin++;
	}
}

void		findpos(void)
{
	int		x;
	int		y;

	y = -1;
	g_cnt_points = 0;
	while (g_map.map[++y])
	{
		x = -1;
		while (g_map.map[y][++x])
			if (g_map.map[y][x] == g_mymark)
				count_all_point(x, y);	
	}
	g_points = (t_coo*)malloc(sizeof(t_coo) * g_cnt_points);
	y = -1;
	g_cnt_points = 0;
	while (g_map.map[++y])
	{
		x = -1;
		while (g_map.map[y][++x])
			if (g_map.map[y][x] == g_mymark)
				check_around_point(x, y);
				// if (can_put_it(x, y) == 1)
				// {
				// 	g_points[g_cnt_points].x = x;
				// 	g_points[g_cnt_points++].y = y;
				// }
	}
	print_points();
}

void	filler_algo(void)
{
	//'X' = 'x' - 32;
	//'O' = 'o' - 32;
	findpos();
}