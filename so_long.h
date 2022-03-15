/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:22:06 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/25 16:04:22 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"

# define KEYPRESS		2
# define KEYEXIT		17

# define A_KEY					0
# define S_KEY					1
# define D_KEY					2
# define W_KEY					13
# define ESC 					53

# define TILE 64
# define HERO   "./assets/hero/hero00.xpm"
# define HERO1  "./assets/hero/hero01.xpm"
# define HERO2  "./assets/hero/hero02.xpm"
# define HERO3  "./assets/hero/hero03.xpm"
# define GOST   "./assets/gost/gost00.xpm"
# define GOST1  "./assets/gost/gost01.xpm"
# define GOST2  "./assets/gost/gost02.xpm"
# define GOST3  "./assets/gost/gost03.xpm"
# define COIN   "./assets/land/collectible.xpm"
# define WALL   "./assets/land/wall.xpm"
# define OUT    "./assets/land/out.xpm"
# define GROUND "./assets/land/ground.xpm"

# define GAME_LOST "Game over"
# define GAME_WON "You won!"

# define ORANGE 0xFFFFFF

typedef struct s_vars {
	void		*mlx;
	void		*win;
	char		**map;
	int			steps;
	size_t		map_width;
	size_t		map_height;
	int			pl_x;
	int			pl_y;
	int			coins;
	int			coins_collected;
	int			bonus;
	int			gameover;
	int			gamewin;
}				t_vars;

void	error(char *name, char *desc);
void	read_map(t_vars *vars, char *path);
void	put_image(t_vars *vars, char *path, int	x, int	y);
int		render_map(t_vars *vars);
int		render_loop(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		endgame(t_vars *vars);
char	*anim_hero(t_vars *vars);
char	*anim_gost(t_vars *vars);
void	move_gost(t_vars *vars);

#endif