/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 04:00:14 by ggunaydi          #+#    #+#             */
/*   Updated: 2023/05/30 05:26:45 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	free_double_array(char **arr)
{
	int	y;

	y = -1;
	while (arr[++y])
		free (arr[y]);
	free(arr);
}

int	ft_strcmp(char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (dst[i] == '\0')
			return (1);
		if (src[i] != dst[i])
			return (1);
		i++;
	}
	return (0);
}

int	name_check(char *str)
{
	char	*str1;
	int		fd;

	str1 = ft_strrchr(str, '.');
	if (!str1 || ft_strlen(str1) != 4)
		return (1);
	if (ft_strcmp(str1, ".ber") == 1)
		return (1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

int	exit_game(t_hp *hp)
{
	free_double_array(hp->map);
	mlx_destroy_image(hp->mlx, hp->bg);
	mlx_destroy_image(hp->mlx, hp->p_img);
	mlx_destroy_image(hp->mlx, hp->c_img);
	mlx_destroy_image(hp->mlx, hp->wall);
	mlx_destroy_image(hp->mlx, hp->exit);
	mlx_destroy_window(hp->mlx, hp->win);
	free(hp->check_arr);
	system("leaks so_long");
	exit(0);
	return (0);
}
