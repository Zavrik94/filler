/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:55:12 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/05 21:05:22 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <stdio.h>
# define CHEAT(x, map) ((x) < 0) ? (x) + (map) : (x)
# define CHEATUP(x, map) ((x) + 1 < (map)) ? (x) + 1 : (map)
# define CHEATDWN(x, map) ((x) - 1 > (map)) ? (x) - 1 : (map)

int		start_input(void);
void	filler_algo(void);
int		**fill_map_numbers(void);

typedef struct s_coordinates t_coo;

struct s_coordinates
{
	int		x;
	int		y;
};

typedef struct	s_map
{
	t_coo	mc;
	t_coo	pc;
	char	**map;
	char	**piece;
	char	mymark;
	char	enmark;
	t_coo	best;
	int		bestsum;
}				t_map;

t_map		g_map;
int			**g_num_map;
int			fd;

#endif
