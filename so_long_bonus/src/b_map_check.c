/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_map_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:30:13 by ggunaydi          #+#    #+#             */
/*   Updated: 2023/05/30 03:59:17 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_so_long.h"

void	read_map(t_hp *hp, char *name, t_control *ctrl)
{
	int		fd;
	char	*str;
	char	*map;
	int		i;

	i = 0;
	map = NULL;
	fd = open(name, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		map = ft_strjoin(map, str);
		free(str);
		str = get_next_line(fd);
	}
	hp->map = ft_split(map, '\n');
	ctrl->map = ft_split(map, '\n');
	hp->max_x = ft_strlen(hp->map[0]);
	while (hp->map[i])
		i++;
	hp->max_y = i;
	hp->win = mlx_new_window(hp->mlx, hp->max_x * 64, hp->max_y * 64, "GG");
	free(map);
}

int	check_objects(t_hp *hp, int x, int y)
{
	hp->check_arr = ft_calloc(3, sizeof(int));
	while (++y < hp->max_y)
	{
		x = -1;
		while (++x < hp->max_x)
		{
			if (hp->map[y][x] == 'P')
			{
				hp->check_arr[0]++;
				hp->px = x;
				hp->py = y;
				hp->map[y][x] = '0';
			}
			else if (hp->map[y][x] == 'C')
				hp->check_arr[1]++;
			else if (hp->map[y][x] == 'E')
				hp->check_arr[2]++;
		}
	}
	hp->coin = hp->check_arr[1];
	if (hp->check_arr[0] != 1 || hp->check_arr[1] < 1
		|| hp->check_arr[2] != 1)
		return (1);
	return (0);
}

int	check_map(t_hp *hp, int x, int y)
{
	while (++y < hp->max_y)
	{
		x = -1;
		while (++x < hp->max_x)
		{
			if (hp->map[y][x] != '1' && hp->map[y][x] != '0' &&
				hp->map[y][x] != 'P' && hp->map[y][x] != 'C' &&
				hp->map[y][x] != 'E' && hp->map[y][x] != 'V')
				return (1);
			if ((x == 0 || x == hp->max_x - 1) && hp->map[y][x] != '1')
				return (1);
			if ((y == 0 || y == hp->max_y -1) && hp->map[y][x] != '1')
				return (1);
		}
		if (ft_strlen(hp->map[y]) != hp->max_x)
			return (1);
	}
	return (check_objects(hp, -1, -1));
}

void	path_finder(t_control *control, int px, int py)
{
	if (control->map[py][px] == 'E')
		control->can_exit = true;
	if (control->map[py][px] == 'C')
		control->coin++;
	control->map[py][px] = '1';
	if (control->map[py + 1][px] != '1')
		path_finder(control, px, py + 1);
	if (control->map[py - 1][px] != '1')
		path_finder(control, px, py - 1);
	if (control->map[py][px + 1] != '1')
		path_finder(control, px + 1, py);
	if (control->map[py][px - 1] != '1')
		path_finder(control, px - 1, py);
}
