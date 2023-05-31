/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:51:46 by ggunaydi          #+#    #+#             */
/*   Updated: 2022/10/24 16:31:13 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief String'e karakter yazma. -> "Gulbahar" --> 'p' * 4 => "ppppahar"
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return void* 
 */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		((unsigned char *)str)[i++] = c;
	}
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char b[] = "Gulbahar";
	int c;

	c = '3';
	size_t len = 3;
	printf("%s",ft_memset(str, c, len));
}
*/