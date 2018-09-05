#include <filler.h>

int		check_enermy_angle()
{
	int		x;
	int		y;
	int		my;
	int		en;

	my = 0;
	en = 0;
	y = -1;
	while (g_map.map[++y])
	{
		x = -1;
		while (g_map.map[y][++x])
		{
			if (g_map.map[y][x] == g_map.mymark || g_map.map[y][x] == g_map.mymark + 32)
				my += x + y;
			if (g_map.map[y][x] == g_map.enmark || g_map.map[y][x] == g_map.enmark + 32)
				en += x + y;
		}
	}
	if (my >= en)
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

int		cheat_coord(int	x, int mc, int status)
{
	int angle;

	angle = check_enermy_angle();
	if (status == 0)
	{
		if (x - 1 <= 0)
			return (mc + x);
		else
			return (x - mc);
		// if (angle == 0)
		// {
		// 	if (x - 1 <= 0) 
		// 		return (mc + x);
		// 	else
		// 		return (mc - 1);
		// }
		// else
		// {
		// 	if (x - 1 <= 0)
		// 		return (0);
		// 	else
		// 		return (x - mc);
		// }
	}
	else
	{
		if (angle == 0)
		{
			if (x - 1 <= 0)
				return (mc + x);
			else
				return (mc - 1);
		}
		else
		{
			if (x - 1 <= 0)
				return (0);
			else
				return (x - mc);
		}
	}
	// if (z = '-')
	// 	return((x - 1 > 0) ? x - 1 : mc - x);
	// else
	// 	return ((x + 1 < mc) ? x + 1 : mc - x);
}

int		check_around_number(int	**map, int	x, int y)
{
	int		minx;
	int		miny;
	int		i;
	int		c;
	int		min;
	int		ischange;

	miny = y - 1;
	minx = x - 1;
	min = 10000000;
	ischange = 0;
	i = -1;
	// ft_printnumbarr(map, g_map.mc.x, g_map.mc.y);
	// write(1, "\n", 1);
	if (map[y][x] == 0)
		return (0);
	//if (x == 17 && y == 1)
		//printf("g_map.mc.y = %d x = %d y = %d maxx = %d miny = %d maxy = %d\n",g_map.mc.y, x , y, maxx, miny, maxy);
	
//map[(minx + c < 0 || minx + c >= g_map.mc.x) ? cheat_coord(minx + c, g_map.mc.x) : minx + x
	while (++i < 3)
	{
		c = -1;
		while (++c < 3)
		{
			// 	printf("x = %d y = %d yc = %d xc = %d\n",x, y, (miny + i < 0 || miny + i >= g_map.mc.y) ? cheat_coord(miny + i, g_map.mc.y, 1) : miny + i, (minx + c < 0 || minx + c >= g_map.mc.x) ? cheat_coord(minx + c, g_map.mc.x, 0) : minx + c);
			if (map[(miny + i < 0 || miny + i >= g_map.mc.y) ? cheat_coord(miny + i, g_map.mc.y, 1) : miny + i][(minx + c < 0 || minx + c >= g_map.mc.x) ? cheat_coord(minx + c, g_map.mc.x, 0) : minx + c] < min && map[(miny + i < 0 || miny + i >= g_map.mc.y) ? cheat_coord(miny +i, g_map.mc.y, 1) : miny + i][(minx + c < 0 || minx + c >= g_map.mc.x) ? cheat_coord(minx + c, g_map.mc.x, 0) : minx + c] > -1) 
			{
				ischange = 1;
				min = map[(miny + i < 0 || miny + i >= g_map.mc.y) ? cheat_coord(miny + i, g_map.mc.y, 1) : miny + i][(minx + c < 0 || minx + c >= g_map.mc.x) ? cheat_coord(minx + c, g_map.mc.x, 0) : minx + c];
				// printf("min = %d", min);
			}
		}
		// printf("\n");
	}
	// printf("\n\n");
	// if (map[CHEATDWN(y, 0)][CHEATDWN(x, 0)] < min && map[CHEATDWN(y, 0)][CHEATDWN(x, 0)] > -1 && (ischange = 1) > 0 )
	// 	min = map[CHEATDWN(y, 0)][CHEATDWN(x, 0)];
	// if (map[CHEATDWN(y, 0)][x] < min && map[CHEATDWN(y, 0)][x] > -1 && (ischange = 1) > 0 )
	// 	min = map[CHEATDWN(y, 0)][x];
	// if (map[CHEATDWN(y, 0)][CHEATUP(x, g_map.mc.x)] < min && map[CHEATDWN(y, 0)][CHEATUP(x, g_map.mc.x)] > -1 && (ischange = 1) > 0 )
	// 	min = map[CHEATDWN(y, 0)][CHEATUP(x, g_map.mc.x)];
	// if (map[y][CHEATDWN(x, 0)] < min && map[y][CHEATDWN(x, 0)] > -1 && (ischange = 1) > 0 )
	// 	min = map[y][CHEATDWN(x, 0)];
	// if (map[y][CHEATUP(x, g_map.mc.x)] < min && map[y][CHEATUP(x, g_map.mc.x)] > -1 && (ischange = 1) > 0 )
	// 	min = map[y][CHEATUP(x, g_map.mc.x)];
	// if (map[CHEATUP(y, g_map.mc.y)][CHEATDWN(x, 0)] < min && map[CHEATUP(y, g_map.mc.y)][CHEATDWN(x, 0)] > -1 && (ischange = 1) > 0 )
	// 	min = map[CHEATUP(y, g_map.mc.y)][CHEATDWN(x, 0)];
	// if (map[CHEATUP(y, g_map.mc.y)][x] < min && map[CHEATUP(y, g_map.mc.y)][x] > -1 && (ischange = 1) > 0 )
	// 	min = map[CHEATUP(y, g_map.mc.y)][x];
	// if (map[CHEATUP(y, g_map.mc.y)][CHEATUP(x, g_map.mc.x)] < min && map[CHEATUP(y, g_map.mc.y)][CHEATUP(x, g_map.mc.x)] > -1 && (ischange = 1) > 0 )
	// 	min = map[CHEATUP(y, g_map.mc.y)][CHEATUP(x, g_map.mc.x)];
	if (ischange)
		return (min + 1);
	else
		return (-1);	
}

int		**fill_map_numbers(void)
{
	// dprintf(fd, "start fill map numb\n");
	int		**map;
	int		i;
	int		x;
	int		y;
	int		angle;

	map = (int**)malloc(sizeof(int*) * g_map.mc.y + 1);
	map[g_map.mc.y] = NULL;
	dprintf(fd, "before 1st write fill map numb\n");
	i = -1;
	while (g_map.map[++i])
	{
		x = -1;
		map[i] = (int*)malloc(sizeof(int) * g_map.mc.x);
		while (g_map.map[i][++x])
		{
			if (g_map.map[i][x] != g_map.enmark && g_map.map[i][x] != g_map.enmark + 32)
				map[i][x] = -1;
			else
				map[i][x] = 0;
		}
	}
	dprintf(fd, "after 1st write fill map numb\n");
	angle = check_enermy_angle();
	// printf("andle = %d\n", angle);
	dprintf(fd, "before 2st write fill map numb\n");
	while (check_dot_map(map))
	{
		if (angle == 1)
		{
			y = g_map.mc.y;
			while (--y > -1)
			{
				x = g_map.mc.x;
				while (--x > -1)
				{
					map[y][x] = check_around_number(map, x , y);
					if (g_map.map[y][x] == g_map.mymark || g_map.map[y][x] == g_map.mymark + 32)
						map[y][x] = -2;
				}
			}
		}
		else
		{
			y = -1;
			while (++y < g_map.mc.y)
			{
				x = -1;
				while (++x < g_map.mc.x)
				{
					map[y][x] = check_around_number(map, x , y);
				}
			}
		}
	}
	//ft_printnumbarr(map, g_map.mc.x, g_map.mc.y);
	dprintf(fd, "end fill map numbers\n");
	return (map);
}