/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:01:38 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/17 10:51:01 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		fd;

void	input_plat(char *line)
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
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	g_map.map[g_map.mc.y] = NULL;
	i = -1;
	while (++i < g_map.mc.y)
	{
		get_next_line(0, &line);
		g_map.map[i] = ft_strscpy(line, 4);
		ft_strdel(&line);
	}
}

void	input_piece(char *line)
{
	int		i;

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
	ft_strdel(&line);
	while (++i < g_map.pc.y)
	{
		get_next_line(0, &line);
		g_map.piece[i] = ft_strscpy(line, 0);
		ft_strdel(&line);
	}
}

int		main(void)
{
	char *line;

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
			ft_strdel(&line);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}
