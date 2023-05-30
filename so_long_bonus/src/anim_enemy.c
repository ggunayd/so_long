/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:10:38 by ggunaydi          #+#    #+#             */
/*   Updated: 2023/05/30 03:23:55 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_so_long.h"

void	enemy(t_hp *hp, int x, int y, int tmp)
{
	while (++x < hp->max_x)
	{
		y = -1;
		while (++y < hp->max_y)
		{
			if (hp->map[y][x] == 'V' && hp->map[y + 1][x] == '0')
			{
				hp->map[y][x] = '0';
				hp->map[y + 1][x] = 'V';
				y++;
				if (x == hp->px && y == hp->py)
					exit_game(hp);
			}
			else if (hp->map[y][x] == 'V' && hp->map[y + 1][x] != '0')
			{
				tmp = y;
				while (hp->map[tmp][x] != '1' && hp->map[tmp][x] != 'C')
					--tmp;
				if (hp->px == x && hp->py == tmp + 1)
					exit_game(hp);
				hp->map[tmp + 1][x] = 'V';
				hp->map[y][x] = '0';
			}
		}
	}
}

void	put_image(t_hp *hp, int x, int y, void *image)
{
	mlx_put_image_to_window(hp->mlx, hp->win, image, x * 64, y * 64);
}

void	clear_env(t_hp *hp)
{
	int	x;
	int	y;

	y = 0;
	while (++y < hp->max_y)
	{
		x = 0;
		while (++x < hp->max_x)
			put_image(hp, x, y, hp->bg);
	}
}

void	draw(t_hp *hp, int x, int y)
{
	char	*temp;

	clear_env(hp);
	while (++y < hp->max_y)
	{
		x = -1;
		while (++x < hp->max_x)
		{
			if (hp->map[y][x] == '1')
				put_image(hp, x, y, hp->wall);
			else if (hp->map[y][x] == 'C')
				put_image(hp, x, y, hp->c_img[hp->anim.c_idx]);
			else if (hp->map[y][x] == 'E')
				put_image(hp, x, y, hp->exit);
			else if (hp->map[y][x] == 'V')
				put_image(hp, x, y, hp->enemy);
		}
	}
	put_image(hp, hp->px, hp->py, hp->p_img[hp->anim.p_idx]);
	temp = ft_itoa(hp->step);
	mlx_string_put(hp->mlx, hp->win, 20, 20, 0xff0000, temp);
	free(temp);
}

void	animator(t_hp *hp, int x, int y)
{
	hp->anim.counter++;
	if (hp->anim.counter == 5)
	{
		hp->anim.c_idx++;
		hp->anim.p_idx++;
		hp->anim.counter = 0;
	}
	if (hp->anim.c_idx > 4)
		hp->anim.c_idx = 0;
	if (hp->anim.p_idx > 3)
		hp->anim.p_idx = 0;
}
