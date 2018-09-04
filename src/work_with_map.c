#include <filler.h>

int		check_dot_map(int **map)
{
	int		x;
	int		y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == -1)
				return (1);
	}
	return (0);
}

int		check_around_number(int	**map, int	x, int y)
{
	int		minx;
	int		miny;
	int		maxx;
	int		maxy;
	int		res;

	miny = y - 1 > 0 ? y - 1 : 0;
	res = 0;
	maxx = x + 1 < g_map.mc.x ? x + 1 : g_map.mc.x;
	maxy = y + 1 < g_map.mc.y ? y + 1 : g_map.mc.y;
	while (miny <= maxy)
	{
		minx = x - 1 > 0 ? x - 1 : 0;
		while (minx <= maxx)
		{
			if (map[miny][minx] )
			minx++;
		}
		miny++;
	}
	return (0);
}

void	fill_map_numbers(void)
{
	int		**map;
	int		i;
	int		x;
	int		y;

	map = (int**)malloc(sizeof(int*) * g_map.mc.y);
	map[g_map.mc.y] = NULL;
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
	while (check_dot_map(map))
	{
		y = -1;
		while (map[++y])
		{
			x = -1;
			while (map[y][++x])
			{
			} 
		}
	}
	//ft_printnumbarr(map, g_map.mc.x, g_map.mc.y);
}