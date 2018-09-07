/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:37:51 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/07 22:09:00 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualizer.h>

static inline void		init_viz(void)
{
	initscr();
	nodelay(stdscr, true);
	curs_set(false);
	cbreak();
	noecho();
	use_default_colors();
	start_color();
	init_pair(P1, COLOR_RED, COLOR_RED);
	init_pair(P2, COLOR_GREEN, COLOR_GREEN);
	init_pair(NEU, COLOR_WHITE, COLOR_WHITE);
}

static inline void		input_plat(char *line)
{
	int		i;

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
}

// static inline void		visualize_it(void)
// {
// 	const int	maplen = ft_strlen(g_map.map[0]);
// 	int			x;
// 	int			y;

// 	y = -1;
// 	while (g_map.map[++y])
// 	{
// 		// mvprintw(y, (COLS - maplen * 2) / 2, "");
// 		x = -1;
// 		while (g_map.map[y][++x])
// 		{
// 			// if (g_map.map[y][x] == 'o' || g_map.map[y][x] == 'O')
// 			// 	attron(COLOR_PAIR(P1));
// 			// else if (g_map.map[y][x] == 'x' || g_map.map[y][x] == 'X')
// 			// 	attron(COLOR_PAIR(P2));
// 			// else
// 			// 	attron(COLOR_PAIR(NEU));
// 			printw("%c ", g_map.map[y][x]);
// 			// dprintf(fd, "%c", g_map.map[y][x]);
// 			// if (g_map.map[y][x] == 'o' || g_map.map[y][x] == 'O')
// 			// 	attroff(COLOR_PAIR(P1));
// 			// else if (g_map.map[y][x] == 'x' || g_map.map[y][x] == 'X')
// 			// 	attroff(COLOR_PAIR(P2));
// 			// else
// 			// 	attroff(COLOR_PAIR(NEU));
// 		}
// 		printw("\n");
// 		// dprintf(fd, "\n");
// 	}
// 	printw("\n");
// 	// dprintf(fd, "\n");
// }

int		main(void)
{
	char	*line;

	fd = open("log1", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	init_viz();
	while (get_next_line(0, &line) > 0)
	{
		printw("%c ", 'x');
		// dprintf(fd, "AAA\n");
		if (ft_strstr(line, "Plateau"))
		{
			// dprintf(fd, "BBB\n");
			input_plat(line);
			printw("%c\n", 'o');
			// visualize_it();
		}
	}
	endwin();
	system("reset");
	return (0);
}
