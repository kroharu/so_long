/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:01:09 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/25 16:33:07 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_collected(t_vars *vars, int x, int y)
{
	vars->map[x][y] = '0';
	put_image(vars, GROUND, y * TILE, x * TILE);
	vars->coins_collected++;
}

void	print_steps(t_vars *vars, int steps)
{
	put_image(vars, WALL, 0, 0);
	if (vars->bonus)
		mlx_string_put(vars->mlx, vars->win, 20, 20, ORANGE, ft_itoa(steps));
	else
		printf("%d\n", vars->steps++);
}

void	ft_move(t_vars *vars, int	x, int y)
{
	if (vars->map[vars->pl_y + y][vars->pl_x + x] == '1')
		return ;
	if (vars->map[vars->pl_y + y][vars->pl_x + x] == 'C')
		coin_collected(vars, vars->pl_y + y, vars->pl_x + x);
	if (vars->map[vars->pl_y + y][vars->pl_x + x] == 'G' && vars->bonus)
		vars->gameover = 1;
	if (vars->map[vars->pl_y + y][vars->pl_x + x] == 'E')
	{
		if (vars->coins_collected == vars->coins)
			vars->gamewin = 1;
		else
			return ;
	}
	print_steps(vars, vars->steps++);
	put_image(vars, GROUND, vars->pl_x * TILE, vars->pl_y * TILE);
	vars->pl_x += x;
	vars->pl_y += y;
	move_gost(vars);
}

int	key_press(int keycode, t_vars *vars)
{
	if (vars->gamewin || vars->gameover)
		endgame(vars);
	if (keycode == A_KEY)
		ft_move(vars, -1, 0);
	if (keycode == D_KEY)
		ft_move(vars, 1, 0);
	if (keycode == S_KEY)
		ft_move(vars, 0, 1);
	if (keycode == W_KEY)
		ft_move(vars, 0, -1);
	if (keycode == ESC)
		endgame(vars);
	return (0);
}

int	endgame(t_vars *vars)
{
	size_t	i;

	if (vars->gameover == 1)
	{
		printf("-------> GAME OVER <----------\n");
		printf("------> your score is %d <-----\n", vars->coins_collected);
	}
	if (vars->gamewin == 1)
	{
		printf("---------> YOU WIN <------------\n");
	}
	i = 0;
	while (i < vars->map_height)
		free(vars->map[i++]);
	free(vars->map);
	free(vars->mlx);
	free(vars->win);
	exit (EXIT_SUCCESS);
}
