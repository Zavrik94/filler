/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_put_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:50:16 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/12 20:31:36 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		first_if(t_coo f)
{
	if (g_map.map[CHEAT(f.y, g_map.mc.y)][CHEAT(f.x, g_map.mc.x)]\
						== g_map.enmark || g_map.map[CHEAT(f.y, g_map.mc.y)]\
						[CHEAT(f.x, g_map.mc.x)] == (g_map.enmark + 32))
		return (1);
	else
		return (0);
}

int		second_if(int counter, t_coo f)
{
	if (counter == 0 && (g_map.map[CHEAT(f.y, g_map.mc.y)]\
		[CHEAT(f.x, g_map.mc.x)] == g_map.mymark \
			|| g_map.map[CHEAT(f.y, g_map.mc.y)]\
				[CHEAT(f.x, g_map.mc.x)] == g_map.mymark + 32))
		return (1);
	else
		return (0);
}

int		can_put_it(int x, int y)
{
	t_coo	f;
	t_coo	p;
	int		counter;

	if ((x + g_map.pc.x > g_map.mc.x) || (y + g_map.pc.y > g_map.mc.y))
		return (0);
	f.y = y;
	p.y = 0;
	counter = 0;
	while (f.y < y + g_map.pc.y && (p.x = 0) > -1)
	{
		f.x = x;
		while (f.x < x + g_map.pc.x)
		{
			if (g_map.map[CHEAT(f.y, g_map.mc.y)][CHEAT(f.x, g_map.mc.x)] \
					!= '.' && g_map.piece[p.y][p.x] == '*')
				(second_if(counter, f) && first_if(f) == 0) ? counter++ : \
					(counter = -1);
			f.x++;
			p.x++;
		}
		f.y++;
		p.y++;
	}
	return ((counter == 0 || counter == -1) ? 0 : 1);
}
