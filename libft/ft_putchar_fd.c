/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:18:47 by ggunaydi          #+#    #+#             */
/*   Updated: 2022/12/01 12:13:48 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fcntl.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// belirtilen dosya tanimlayicisina (fd) c karakterini yazar.
/*
int main()
{
    int fd = open("salakayberk.txt", O_RDWR);
    ft_putchar_fd('a', fd);
}
*/
