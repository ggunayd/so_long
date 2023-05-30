/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:14:06 by ggunaydi          #+#    #+#             */
/*   Updated: 2023/05/30 03:17:35 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"b_so_long.h"

void	*file_to_img(t_hp *hp, char *path)
{
	int	a;

	return (mlx_xpm_file_to_image(hp->mlx, path, &a, &a));
}

void	init(t_hp	*hp, t_control *ctrl)
{
	hp->mlx = mlx_init();
	hp->step = 0;
	hp->coin = 0;
	ctrl->coin = 0;
	ctrl->can_exit = false;
	hp->anim.counter = 0;
	hp->anim.p_idx = 0;
	hp->anim.c_idx = 0;
	hp->enemy_speed = 0;
}

void	init_images(t_hp *hp)
{
	hp->p_img[0] = file_to_img(hp, "sprites/player/0.xpm");
	hp->p_img[1] = file_to_img(hp, "sprites/player/1.xpm");
	hp->p_img[2] = file_to_img(hp, "sprites/player/2.xpm");
	hp->p_img[3] = file_to_img(hp, "sprites/player/3.xpm");
	hp->c_img[0] = file_to_img(hp, "sprites/coin/0.xpm");
	hp->c_img[1] = file_to_img(hp, "sprites/coin/1.xpm");
	hp->c_img[2] = file_to_img(hp, "sprites/coin/2.xpm");
	hp->c_img[3] = file_to_img(hp, "sprites/coin/3.xpm");
	hp->c_img[4] = file_to_img(hp, "sprites/coin/4.xpm");
	hp->wall = file_to_img(hp, "sprites/rock.xpm");
	hp->exit = file_to_img(hp, "sprites/exit.xpm");
	hp->bg = file_to_img(hp, "sprites/background.xpm");
	hp->enemy = file_to_img(hp, "sprites/enemy.xpm");
}
