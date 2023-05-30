/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:18:44 by ggunaydi          #+#    #+#             */
/*   Updated: 2023/05/30 03:52:23 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_so_long.h"

void	move(int dir_x, int dir_y, t_hp *hp)
{
	if (hp->map[hp->py + dir_y][hp->px + dir_x] == 'V')
		exit_game(hp);
	if (hp->map[hp->py + dir_y][hp->px + dir_x] == 'E' && hp->coin == 0)
		exit_game(hp);
	if (ft_strchr("0CE", hp->map[hp->py + dir_y][hp->px + dir_x]) != NULL)
	{
		if (hp->map[hp->py + dir_y][hp->px + dir_x] == 'C')
		{
			hp->map[hp->py + dir_y][hp->px + dir_x] = '0';
			hp->coin--;
		}
		hp->px += dir_x;
		hp->py += dir_y;
		hp->step++;
	}
}

int	keyhook(int keycode, t_hp *hp)
{
	if (keycode == 53)
		exit_game(hp);
	else if (keycode == 0)
		move(-1, 0, hp);
	else if (keycode == 1)
		move(0, 1, hp);
	else if (keycode == 2)
		move(1, 0, hp);
	else if (keycode == 13)
		move(0, -1, hp);
	return (0);
}
