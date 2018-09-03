/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:55:12 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/03 21:55:16 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

void	start_input(void);

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

}				t_map;

t_map		g_map;

#endif
