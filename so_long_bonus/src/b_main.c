/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:13:47 by ggunaydi          #+#    #+#             */
/*   Updated: 2023/05/31 22:01:32 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_so_long.h"

void	exit_path_finder(t_hp *hp)
{
	free_double_array(hp->map);
	mlx_destroy_window(hp->mlx, hp->win);
	free(hp->check_arr);
	ft_printf("Path finder error\n");
	exit(1);
}

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
		error("Error Argument !");
	init(&hp, &control);
	if (name_check(av[1]) == 1)
		error("Error Name !");
	read_map(&hp, av[1], &control);
	if (check_map(&hp, -1, -1) == 1)
		error("Error");
	path_finder(&control, hp.px, hp.py);
	free_double_array(control.map);
	if (control.can_exit == false || control.coin != hp.coin)
		exit_path_finder(&hp);
	init_images(&hp);
	mlx_loop_hook(hp.mlx, update, &hp);
	mlx_hook(hp.win, 2, 0, keyhook, &hp);
	mlx_hook(hp.win, 17, 0, exit_game, &hp);
	mlx_loop(hp.mlx);
}
