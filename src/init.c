/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 04:22:51 by ggunaydi          #+#    #+#             */
/*   Updated: 2023/05/30 04:23:47 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	init(t_hp	*hp, t_control *ctrl)
{
	hp->mlx = mlx_init();
	hp->step = 0;
	hp->coin = 0;
	ctrl->coin = 0;
	ctrl->can_exit = false;
}

void	*file_to_img(t_hp *hp, char *path)
{
	int	a;

	return (mlx_xpm_file_to_image(hp->mlx, path, &a, &a));
}

void	init_images(t_hp *hp)
{
	int	a;

	hp->p_img = file_to_img(hp, "sprites/player/0.xpm");
	hp->c_img = file_to_img(hp, "sprites/coin/0.xpm");
	hp->wall = file_to_img(hp, "sprites/rock.xpm" );
	hp->exit = file_to_img(hp, "sprites/exit.xpm");
	hp->bg = file_to_img(hp, "sprites/background.xpm");
}
