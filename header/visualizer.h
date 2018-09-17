/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:55:12 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/17 23:56:28 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../libft/libft.h"
# include <ncurses.h>
# include <stdio.h>
# include <time.h>

typedef struct	s_coordinates
{
	int		x;
	int		y;

}				t_coo;

typedef struct	s_map
{
	t_coo	mc;
	char	**map;
	t_coo	pc;
	char	**piece;
	t_coo	fin;
	char	*o;
	char	*x;

	WINDOW	*m;
	WINDOW	*p;

}				t_map;

enum			e_pcolors
{
	P1 = 10,
	P2,
	STAR,
	NEU
};

void			init_vis(t_map *m);
void			input_plat1(char *line, t_map *m);
void			input_piece1(char *line, t_map *m);
void			print_winner(t_map *m);

#endif
