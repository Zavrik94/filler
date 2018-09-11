#include <filler.h>

void	cut_piece()
{
	t_coo	a;
	t_coo	min;
	t_coo	max;
	t_coo	len;
	char 	**res;
	t_coo	tmp;

	a.y = -1;
	max.x = 0;
	max.y = 0;
	min.x = g_map.pc.x;
	min.y = g_map.pc.y;
	// ft_printarr(g_map.piece);
	while (g_map.piece[++a.y])
	{
		a.x = -1;
		while (g_map.piece[a.y][++a.x])
			if (g_map.piece[a.y][a.x] == '*')
			{
				if (a.x < min.x)
					min.x = a.x;
				if (a.y < min.y)
					min.y = a.y;
				if (a.x > max.x)
					max.x = a.x;
				if (a.y > max.y)
					max.y = a.y;
			}
	}
	len.y = max.y - min.y + 1;
	len.x = max.x - min.x + 1;
	// printf("mix = %d miny = %d maxx = %d maxy = %d x = %d y = %d\n",min.x, min.y, max.x, max.y, len.x, len.y);
	res = (char**)malloc(sizeof(char*) * (len.y + 1));
	res[len.y] = NULL;
	tmp.y = -1;
	g_map.old_pc.x = min.x;
	g_map.old_pc.y = min.y;
	while (++tmp.y < len.y)
	{
		tmp.x = -1;
		min.x = max.x - len.x + 1;
		res[tmp.y] = (char*)malloc(sizeof(char) * (len.x + 1));
		res[tmp.y][len.x] = '\0';  
		while (++tmp.x < len.x)
		{
			// printf("%c", g_map.piece[min.y][min.x]);
			res[tmp.y][tmp.x] = g_map.piece[min.y][min.x];
			min.x++;
		}
		// printf("\n");
		min.y++;
	}
	free(g_map.piece);
	g_map.piece = ft_copyarr(res);
	free(res);
	// ft_printarr(g_map.piece);
	g_map.pc.x = len.x;
	g_map.pc.y = len.y;
}