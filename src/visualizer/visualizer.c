/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:37:51 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/17 15:36:52 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualizer.h>

static inline void		clear_window(WINDOW *w, int height, int width)
{
	int			y;
	int			x;

	y = -1;
	while (++y < height)
	{
		wmove(w, y, 0);
		x = -1;
		while (++x < width)
		{
			wattron(w, COLOR_PAIR(NEU));
			wprintw(w, ". ");
			wattroff(w, COLOR_PAIR(NEU));
		}
	}
}

static inline void		print_the_dot(WINDOW *w, char mp)
{
	if (mp == 'o' || mp == 'O')
		wattron(w, COLOR_PAIR(P1));
	else if (mp == 'x' || mp == 'X')
		wattron(w, COLOR_PAIR(P2));
	else if (mp == '*')
		wattron(w, COLOR_PAIR(STAR));
	else
		wattron(w, COLOR_PAIR(NEU));
	wprintw(w, "%c ", mp);
	if (mp == 'o' || mp == 'O')
		wattroff(w, COLOR_PAIR(P1));
	else if (mp == 'x' || mp == 'X')
		wattroff(w, COLOR_PAIR(P2));
	else if (mp == '*')
		wattroff(w, COLOR_PAIR(STAR));
	else
		wattroff(w, COLOR_PAIR(NEU));
}

static inline void		visualize_piece(t_map *m)
{
	int			y;
	int			x;
	const int	height = m->mc.y / 2;
	const int	width = m->mc.x / 2;

	if (m->p == NULL)
		m->p = newwin(height, width, 2, COLS / 2 + m->mc.x);
	clear_window(m->p, height, width);
	y = -1;
	while (m->piece[++y])
	{
		wmove(m->p, y, 0);
		x = -1;
		while (m->piece[y][++x])
		{
			print_the_dot(m->p, m->piece[y][x]);
		}
	}
	box(m->p, 0, 0);
	wrefresh(m->p);
}

static inline void		visualize_map(t_map *m)
{
	int			x;
	int			y;

	if (m->m == NULL)
		m->m = newwin(m->mc.y, m->mc.x * 2, 2, COLS / 2 - m->mc.x);
	y = -1;
	while (m->map[++y])
	{
		wmove(m->m, y, 0);
		x = -1;
		while (m->map[y][++x])
		{
			print_the_dot(m->m, m->map[y][x]);
		}
	}
	box(m->m, 0, 0);
	wrefresh(m->m);
	usleep(30000);
}

static inline void		print_winner(t_map *m)
{
	ft_putstr("Player \'");
	ft_putchar((m->fin.x > m->fin.y) ? 'X' : 'O');
	ft_putstr("\' win!!!\nWith ");
	ft_putnbr((m->fin.x > m->fin.y) ? m->fin.x : m->fin.y);
	ft_putstr(" win points\n");
}

int						main(void)
{
	t_map	m;
	char	*line;

	init_vis(&m);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			input_plat1(line, &m);
			visualize_map(&m);
		}
		else if (ft_strstr(line, "Piece"))
		{
			input_piece1(line, &m);
			visualize_piece(&m);
		}
		else if ((m.o = ft_strstr(line, "== O fin: ")))
			m.fin.y = ft_atoi(m.o + 9);
		else if ((m.x = ft_strstr(line, "== X fin: ")))
			m.fin.x = ft_atoi(m.x + 9);
		free(line);
	}
	endwin();
	print_winner(&m);
	return (0);
}
