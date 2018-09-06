
#include <filler.h>

void	input_plat(char *line)
{
	// dprintf(fd, "start input plat\n");
	int 	i;

	i = -1;
	g_map.mc.y = 0;
	while (line[++i])
		if (line[i] == ' ' && g_map.mc.y == 0)
			g_map.mc.y = ft_atoi(line + i);
		else if (line[i] == ' ')
			g_map.mc.x = ft_atoi(line + i);
	g_map.map = (char**)malloc(sizeof(char*) * (g_map.mc.y + 1));
	get_next_line(0, &line);
	g_map.map[g_map.mc.y] = NULL;
	i = -1;
	while (++i < g_map.mc.y)
	{
		get_next_line(0, &line);
		g_map.map[i] = line + 4;
	}
	// dprintf(fd, "end input plat\n");
}

void	input_piece(char *line)
{
	// dprintf(fd, "start input piece\n");
	int 	i;

	i = -1;
	g_map.pc.y = 0;
	while (line[++i])
		if (line[i] == ' ' && g_map.pc.y == 0)
			g_map.pc.y = ft_atoi(line + i);
		else if (line[i] == ' ')
			g_map.pc.x = ft_atoi(line + i);
	g_map.piece = (char**)malloc(sizeof(char*) * (g_map.pc.y + 1));
	g_map.piece[g_map.pc.y] = NULL;
	i = -1;
	while (++i < g_map.pc.y)
	{
		get_next_line(0, &line);
		g_map.piece[i] = line;
	}
	// ft_printarr(g_map.piece);
	cut_piece();
	// dprintf(fd, "end input piece\n");
}

int		main(void)
{
	// dup2(open("test", O_RDONLY), 0);
	char *line;

	fd = open("check", O_RDWR);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			input_plat(line);
		else if (ft_strstr(line, "Piece"))
		{
			input_piece(line);
			filler_algo();
		}
		else if (ft_strstr(line, "azavrazh"))
		{
			if (ft_strstr(line, "p1"))
			{
				g_map.mymark = 'O';
				g_map.enmark = 'X';
			}
			else if ((ft_strstr(line, "p2")))
			{
				g_map.mymark = 'X';
				g_map.enmark = 'O';
			}
		}
	}
	return (0);
}