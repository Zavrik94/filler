
#include <filler.h>
#include <stdio.h>

void	input_plat(char *line)
{
	int 	i;

	i = -1;
	g_map.mc.y = 0;
	while (line[++i])
		if (line[i] == ' ' && g_map.mc.y == 0)
			g_map.mc.y = ft_atoi(line + i);
		else if (line[i] == ' ')
			g_map.mc.x = ft_atoi(line + i);
	//printf("x = %d y = %d\n", g_map.map_x, g_map.map_y);
	g_map.map = (char**)malloc(sizeof(char*) * (g_map.mc.y + 1));
	get_next_line(0, &line);
	g_map.map[g_map.mc.y + 1] = NULL;
	i = -1;
	while (++i < g_map.mc.y)
	{
		get_next_line(0, &line);
		g_map.map[i] = line + 4;
	}
	//ft_printarr(g_map.map);
}

void	input_piece(char *line)
{
	int 	i;

	i = -1;
	g_map.pc.y = 0;
	while (line[++i])
		if (line[i] == ' ' && g_map.pc.y == 0)
			g_map.pc.y = ft_atoi(line + i);
		else if (line[i] == ' ')
			g_map.pc.x = ft_atoi(line + i);
	//printf("x = %d y = %d\n", g_map.pc.x, g_map.pc.y);
	
}

void	start_input(void)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			input_plat(line);
		if (ft_strstr(line, "Piece"))
			input_piece(line);
	}
}