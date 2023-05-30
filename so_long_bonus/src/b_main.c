/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:13:47 by ggunaydi          #+#    #+#             */
/*   Updated: 2023/05/30 03:24:19 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_so_long.h"

int	update(t_hp *hp)
{
	hp->enemy_speed++;
	draw(hp, -1, -1);
	animator(hp, -1, -1);
	if (hp->enemy_speed == 30)
	{
		enemy(hp, -1, -1, 666);
		hp->enemy_speed = 0;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_hp		hp;
	t_control	control;

	if (ac != 2)
		error("Hatali arguman !");
	init(&hp, &control);
	if (name_check(av[1]) == 1)
		error("Hatali isim");
	read_map(&hp, av[1], &control);
	if (check_map(&hp, -1, -1) == 1)
		error("Error");
	path_finder(&control, hp.px, hp.py);
	free_double_array(control.map);
	if (control.can_exit == false || control.coin != hp.coin)
		exit(0);
	init_images(&hp);
	mlx_loop_hook(hp.mlx, update, &hp);
	mlx_hook(hp.win, 2, 0, keyhook, &hp);
	mlx_hook(hp.win, 17, 0, exit_game, &hp);
	mlx_loop(hp.mlx);
}
