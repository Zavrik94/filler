/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:55:12 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/17 23:49:29 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <stdio.h>
# define CHEAT2(x, map) ((x) < 0) ? (x) + (map) : (x) - (map) + 1
# define CHEAT(x, map) ((x) < 0) || (x) >= (map) ? (CHEAT2((x), (map))) : (x)

typedef struct s_coordinates	t_coo;

struct			s_coordinates
{
	int		x;
	int		y;
};

typedef struct	s_map
{
	t_coo		mc;
	t_coo		pc;
	t_coo		old_pc;
	char		**map;
	char		**piece;
	char		mymark;
	char		enmark;
	t_coo		best;
	int			bestsum;
}				t_map;

int				**init_map(void);
void			cut_piece(void);
int				start_input(void);
void			filler_algo(void);
int				**fill_map_numbers(void);
int				cheat_coord(int x, int mc, int status);
int				if_check(int **map, t_coo min, int minn, t_coo i);
int				return_min(int **map, t_coo min, t_coo i);
int				can_put_it(int x, int y);
int				calculate_piece(int x, int y);
void			free_all(void);

t_map			g_map;
int				**g_num_map;

#endif
