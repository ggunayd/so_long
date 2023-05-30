/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_so_long.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:22:01 by ggunaydi          #+#    #+#             */
/*   Updated: 2023/05/30 03:28:55 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_SO_LONG_H
# define B_SO_LONG_H

# include "../mlx/mlx.h"
# include "ft_printf.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <stdbool.h>

typedef struct s_anim
{
	int	counter;
	int	c_idx;
	int	p_idx;
}	t_anim;

typedef struct s_hp
{
	void	*mlx;
	void	*win;
	char	**map;
	int		px;
	int		py;
	int		coin;
	int		max_x;
	int		max_y;
	void	*p_img[4];
	void	*c_img[5];
	void	*wall;
	void	*bg;
	void	*exit;
	void	*enemy;
	int		step;
	int		*check_arr;
	t_anim	anim;
	int		enemy_speed;
}	t_hp;

typedef struct s_control
{
	char	**map;
	int		coin;
	bool	can_exit;
}	t_control;

int		ft_strcmp(char *src, char *dst);
int		name_check(char *str);
void	error(char *str);
void	read_map(t_hp *hp, char *name, t_control *ctrl);
int		check_objects(t_hp *hp, int x, int y);
int		check_map(t_hp *hp, int x, int y);
void	move(int dir_x, int dir_y, t_hp *hp);
int		keyhook(int keycode, t_hp *hp);
void	init(t_hp	*hp, t_control *ctrl);
void	init_images(t_hp *hp);
void	path_finder(t_control *control, int px, int py);
void	free_double_array(char **arr);
int		exit_game(t_hp *hp);
void	enemy(t_hp *hp, int x, int y, int tmp);
void	draw(t_hp *hp, int x, int y);
void	animator(t_hp *hp, int x, int y);

#endif
