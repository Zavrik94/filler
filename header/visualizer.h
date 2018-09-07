/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:55:12 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/07 21:59:45 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUZLIZER_H
# define VISUZLIZER_H

# include "../libft/libft.h"
# include <ncurses.h>
# include <time.h>
// # define COMMON_HEIGHT		

#include <stdio.h>

typedef struct s_coordinates t_coo;

struct s_coordinates
{
	int		x;
	int		y;
};

typedef struct	s_map
{
	t_coo	mc;
	char	**map;

}				t_map;

enum	PLAYER_COLORS
{
	P1,
	P2,
	NEU
};

t_map			g_map;

int				fd;

#endif
