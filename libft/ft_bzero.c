/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:50:48 by ggunaydi          #+#    #+#             */
/*   Updated: 2022/12/01 12:46:04 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief String'imize n kadar 0 yaziyor yani NULL('\0').
 * 
 * @param s Stringimiz
 * @param n len ya da kadar.
 * @return void* 
 */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
	{
		*((unsigned char *)s) = 0;
		s++;
	}
}
