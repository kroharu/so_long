/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_gost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:42:56 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/25 16:33:21 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_pos(t_vars *vars, int *a, int d1, int d2)
{
	int		x;
	int		y;

	x = a[0];
	y = a[1];
	if (vars->map[x + d1][y + d2] == '0')
	{
		put_image(vars, GROUND, y * TILE, x * TILE);
		vars->map[x][y] = '0';
		vars->map[x + d1][y + d2] = 'G';
	}
	if ((x + d1 == vars->pl_y) && (y + d2 == vars->pl_x))
		vars->gameover = 1;
}

void	move(t_vars *vars, size_t x, size_t y)
{
	int	rand;
	int	dir;
	int	a[2];

	a[0] = x;
	a[1] = y;
	rand = ((vars->steps * x - y) / x + vars->coins_collected * y) % 2;
	if (rand == 1)
	{
		dir = vars->pl_y - x;
		if (dir < 0)
			move_pos(vars, a, -1, 0);
		else if (dir > 0)
			move_pos(vars, a, 1, 0);
	}
	else
	{
		dir = vars->pl_x - y;
		if (dir < 0)
			move_pos(vars, a, 0, -1);
		else if (dir > 0)
			move_pos(vars, a, 0, 1);
	}
}

void	move_gost(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < vars->map_height)
	{
		j = 0;
		while (j < vars->map_width)
		{
			if (vars->map[i][j] == 'G' && vars->bonus)
			{
				move(vars, i, j);
				j++;
				i++;
			}
			j++;
		}
		i++;
	}
}
