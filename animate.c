/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:15:27 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/25 12:40:02 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*anim_hero(t_vars *vars)
{
	static int	loop = 0;

	if (!vars->bonus)
		return (HERO);
	loop++;
	if (loop / 10 == 0)
		return (HERO);
	if (loop / 20 == 1)
		return (HERO1);
	if (loop / 30 == 2)
		return (HERO2);
	if (loop / 40 == 3)
		return (HERO3);
	if (loop / 50 == 5)
		return (HERO2);
	if (loop / 60 == 6)
		return (HERO1);
	if (loop / 70 == 7)
	{
		loop = 0;
		return (HERO);
	}
	return (HERO);
}

char	*anim_gost(t_vars *vars)
{
	static int	loop = 0;

	if (!vars->bonus)
		return (GOST);
	loop++;
	if (loop / 10 == 0)
		return (GOST);
	if (loop / 20 == 1)
		return (GOST1);
	if (loop / 30 == 2)
		return (GOST2);
	if (loop / 40 == 3)
		return (GOST3);
	if (loop / 50 == 5)
		return (GOST2);
	if (loop / 60 == 6)
		return (GOST1);
	if (loop / 70 == 7)
	{
		loop = 0;
		return (GOST);
	}
	return (GOST);
}
