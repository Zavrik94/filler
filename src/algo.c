#include <filler.h>


int		can_put_it(int	x, int	y)
{
	int		tmp_x;
	int		fx;
	int		fy;
	tmp_x = x;

	if (x + g_map.pc.x - 1 > g_map.mc.x)
		return (0);
	if (y + g_map.pc.y - 1 > g_map.mc.y)
		return (0);
	fy = y;
	while (fy < y + g_map.pc.y)
	{
		while (fx < x + g_map.pc.x)
		{
			if (g_map.map[fy][fx] != '.' && g_map.map[fy][fx] != g_mymark && g_map.map[fy][fx] != g_mymark - 32)
				return (0);
			fx++;
		}
		fy++;
	}
	return (1);
}

void		findpos(void)
{
	int		x;
	int		y;

	y = -1;
	while (g_map.map[++y])
	{
		x = -1;
		while (g_map.map[y][++x])
		{
			if (g_map.map[y][x] == g_mymark || g_map.map[y][x] == (g_mymark - 32))
			{
				if (can_put_it(x, y) == 1)
					printf("%d %d\n", y, x);
			}
		}
	}
}

void	filler_algo(void)
{
	//'X' = 'x' - 32;
	//'O' = 'o' - 32;
	findpos();
}