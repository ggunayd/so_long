/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 04:11:31 by ggunaydi          #+#    #+#             */
/*   Updated: 2023/05/31 22:00:37 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_path_finder(t_hp *hp)
{
	free_double_array(hp->map);
	mlx_destroy_window(hp->mlx, hp->win);
	free(hp->check_arr);
	ft_printf("Path finder error\n");
	exit(1);
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

int	update(t_hp *hp)
{
	int	x;
	int	y;

	clear_env(hp);
	y = -1;
	while (++y < hp->max_y)
	{
		x = -1;
		while (++x < hp->max_x)
		{
			if (hp->map[y][x] == '1')
				put_image(hp, x, y, hp->wall);
			else if (hp->map[y][x] == 'C')
				put_image(hp, x, y, hp->c_img);
			else if (hp->map[y][x] == 'E')
				put_image(hp, x, y, hp->exit);
		}
	}
	put_image(hp, hp->px, hp->py, hp->p_img);
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
	if (check_map (&hp, -1, -1) == 1)
		error("Error");
	init_images(&hp);
	path_finder(&control, hp.px, hp.py);
	if (control.can_exit == false || control.coin != hp.coin)
		exit_path_finder(&hp);
	free_double_array(control.map);
	mlx_loop_hook(hp.mlx, update, &hp);
	mlx_hook(hp.win, 2, 0, keyhook, &hp);
	mlx_hook(hp.win, 17, 0, exit_game, &hp);
	mlx_loop(hp.mlx);
}
